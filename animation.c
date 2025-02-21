/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:42:01 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/21 15:01:18 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	santa_img_move(t_var *var, int x, int y)
{
	if ((var->stock_keycode == S_bottom && var->prev_keycode_lr == D_right)
		|| var->map->move == 0 || (var->stock_keycode == Q_kill
			&& var->prev_keycode_lr == D_right)
		|| var->stock_keycode == D_right)
		mlx_put_image_to_window(var->mlx, var->win,
			var->p_a[0][var->i].img, x, y);
	else if (var->stock_keycode == A_left || (var->stock_keycode == S_bottom
			&& var->prev_keycode_lr == A_left) || (var->stock_keycode == Q_kill
			&& var->prev_keycode_lr == A_left))
		mlx_put_image_to_window(var->mlx, var->win,
			var->p_a[1][var->i].img, x, y);
}

int	santa_dead_or_killer(t_var *var)
{
	if (var->stock_keycode == Q_kill && var->map->tab[var->santa.y / 80]
		[var->santa.x / 80] == 'W' && var->i_wait_fight != 0
		&& var->i_wait_fight < 3)
	{
		kill_ennemy(var, 0);
		return (0);
	}
	else if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'D')
	{
		if (var->stock_keycode == A_left || var->prev_keycode_lr == A_left)
			mlx_put_image_to_window(var->mlx, var->win, var->dead[1].img,
				var->santa.x, var->santa.y);
		else
			mlx_put_image_to_window(var->mlx, var->win, var->dead[0].img,
				var->santa.x, var->santa.y);
		return (0);
	}
	return (1);
}

void	santa_anim(t_var *var, int x, int y)
{
	if (santa_dead_or_killer(var) == 0)
		return ;
	else if (var->map->tab[y / 80][x / 80] == 'T')
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
		|| var->stock_keycode == A_left || var->stock_keycode == S_bottom
		|| var->stock_keycode == Q_kill)
		santa_img_move(var, x, y);
	else if (var->stock_keycode == W_top && var->prev_keycode_lr == D_right)
		mlx_put_image_to_window(var->mlx, var->win, var->p[0].img, x, y);
	else if (var->stock_keycode == W_top && var->prev_keycode_lr == A_left)
		mlx_put_image_to_window(var->mlx, var->win, var->p[1].img, x, y);
}
