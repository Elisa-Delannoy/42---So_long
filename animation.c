/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:42:01 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/19 13:26:29 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	santa_anim(t_var *var, int x, int y)
{
	if (var->map->tab[y / 80][x / 80] == 'T')
	{
		if (var->stock_keycode == A_left || (var->stock_keycode != A_left
				&& var->prev_keycode_lr == A_left))
			mlx_put_image_to_window(var->mlx, var->win,
				var->pp_a[1][var->i].img, x, y);
		else
			mlx_put_image_to_window(var->mlx, var->win,
				var->pp_a[0][var->i].img, x, y);
	}
	else if (var->map->move == 0 || var->stock_keycode == D_right
		|| var->stock_keycode == A_left || var->stock_keycode == S_bottom)
	{
		if (var->map->move == 0 || var->stock_keycode == D_right || (var
				->stock_keycode == S_bottom && var->prev_keycode_lr == D_right))
			mlx_put_image_to_window(var->mlx, var->win,
				var->p_a[0][var->i].img, x, y);
		else if (var->stock_keycode == A_left || (var->stock_keycode == S_bottom
				&& var->prev_keycode_lr == A_left))
			mlx_put_image_to_window(var->mlx, var->win,
				var->p_a[1][var->i].img, x, y);
	}
}

void	ennemies_anim(t_var *var)
{
		// printf("%d\n", var->i_M );
		// printf("%d\n",var->e.y / 80);
		// printf("%d\n", var->e.x / 80);
	if (var->map->tab[var->pos_ennemy.y / 80][var->pos_ennemy.x / 80] == 'M' && var->i_loop == 0)
	{
		// printf("%d\n", var->e.y / 80);
		// printf("%d\n", var->e.x / 80);
		// printf("%d\n", var->i_loop);
		// printf("%c\n", var->map->tab[var->pos_ennemy.y / 80][var->pos_ennemy.x / 80]);
		// printf("%c\n", var->map->tab[e.y/ 80][e.x / 80]);
		mlx_put_image_to_window(var->mlx, var->win,	var->bg.img, var->e.x,var->e.y);
		if (var->map->tab[var->e.y / 80 + 1][var->e.x / 80] == '0')
			var->e.y =var->e.y + 80;
		else if (var->map->tab[var->e.y / 80 - 1][var->e.x / 80] == '0')
			var->e.y =var->e.y - 80;
		else if (var->map->tab[var->e.y / 80][var->e.x / 80 + 1] == '0')
			var->e.x = var->e.x + 80;
		else if (var->map->tab[var->e.y / 80][var->e.x / 80 - 1] == '0')
			var->e.x = var->e.x - 80;
		mlx_put_image_to_window(var->mlx, var->win,	var->ennemy.img, var->e.x,var->e.y);
	}
}

