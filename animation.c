/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:42:01 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/20 00:50:36 by edelanno         ###   ########.fr       */
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
	int i = 0;
	
	while (var->e[i].x != 0 && (var->map->tab[var->pos_ennemy[i].y][var->pos_ennemy[i].x] == 'M'
		|| var->map->tab[var->pos_ennemy[i].y][var->pos_ennemy[i].x] == 'K'))
	{
		// printf("boucle\n");
		if (var->i_loop == 0)
		{
			// printf("%d\n", var->previous_keycode);
		// printf("e y%d\n", var->e[i].y + 1);
		// printf("santa y%d\n", var->santa.x / 80);
		// printf("e x %d\n", var->e[i].x);
		// printf("santa x%d\n", var->santa.y / 80);
			if (var->e[i].y != var->santa.x / 80 || var->e[i].x != var->santa.y / 80)
				mlx_put_image_to_window(var->mlx, var->win,	var->bg.img, var->e[i].y * 80, var->e[i].x * 80);
			if (var->map->tab[var->e[i].x + 1][var->e[i].y ] == '0')
				var->e[i].x =var->e[i].x + 1;
			else if (var->map->tab[var->e[i].x - 1][var->e[i].y ] == '0')
				var->e[i].x =var->e[i].x - 1;
			else if (var->map->tab[var->e[i].x][var->e[i].y + 1] == '0')
				var->e[i].y = var->e[i].y + 1;
			else if (var->map->tab[var->e[i].x ][var->e[i].y - 1] == '0')
				var->e[i].y = var->e[i].y - 1;
			if (var->map->tab[var->pos_ennemy[i].y][var->pos_ennemy[i].x] == 'M')
				mlx_put_image_to_window(var->mlx, var->win,	var->ennemy.img, var->e[i].y * 80, var->e[i].x * 80);		
			else if (var->map->tab[var->pos_ennemy[i].y][var->pos_ennemy[i].x] == 'K' && (var->e[i].y != var->santa.x / 80 || var->e[i].x != var->santa.y / 80))
				mlx_put_image_to_window(var->mlx, var->win,	var->bg.img, var->e[i].y * 80, var->e[i].x * 80);
			
		}
		if (var->e[i].y == (var->santa.x / 80) && var->e[i].x == (var->santa.y / 80) && var->map->tab[var->pos_ennemy[i].y][var->pos_ennemy[i].x] == 'M')
		{
			if (var->stock_keycode == A_left || var->prev_keycode_lr == A_left)
					mlx_put_image_to_window(var->mlx, var->win,	var->dead[1].img, var->santa.x, var->santa.y);
			else
				mlx_put_image_to_window(var->mlx, var->win,	var->dead[0].img, var->santa.x, var->santa.y);
			exit_game(var);
		}
		i++;
	}
}

void	kill_ennemy(t_var *var)
{
	int	i;
	// int	j;
	// int	k;

	i = 0;
	// k = 0;
	while (var->e[i].x != 0 && var->stock_keycode == Q_kill)
	{

		if (var->e[i].y - 1 == var->santa.x / 80 && var->e[i].x == var->santa.y / 80)
		{
			mlx_put_image_to_window(var->mlx, var->win,	var->santa_fight[0].img, var->santa.x, var->santa.y);
			mlx_put_image_to_window(var->mlx, var->win,	var->bg.img, var->e[i].y * 80, var->e[i].x * 80);
			var->map->tab[var->pos_ennemy[i].y][var->pos_ennemy[i].x] = 'K';
			// k++;
			// var->stock_keycode = D_right;
		}
		else if (var->e[i].y + 1 == var->santa.x / 80 && var->e[i].x == var->santa.y / 80)
		{
			mlx_put_image_to_window(var->mlx, var->win,	var->santa_fight[1].img, var->santa.x, var->santa.y);
			mlx_put_image_to_window(var->mlx, var->win,	var->bg.img, var->e[i].y * 80, var->e[i].x * 80);
			var->map->tab[var->pos_ennemy[i].y][var->pos_ennemy[i].x] = 'K';
			// k++;
			// var->stock_keycode = A_left;
		}
		else if (var->e[i].y == var->santa.x / 80 && var->e[i].x + 1 == var->santa.y / 80)
		{
			mlx_put_image_to_window(var->mlx, var->win,	var->santa_fight[2].img, var->santa.x, var->santa.y);
			mlx_put_image_to_window(var->mlx, var->win,	var->bg.img, var->e[i].y * 80, var->e[i].x * 80);
			var->map->tab[var->pos_ennemy[i].y][var->pos_ennemy[i].x] = 'K';
			// k++;
			// var->stock_keycode = A_left;
		}
		else if (var->e[i].y == var->santa.x / 80 && var->e[i].x - 1 == var->santa.y / 80)
		{
			mlx_put_image_to_window(var->mlx, var->win,	var->santa_fight[3].img, var->santa.x, var->santa.y);
			mlx_put_image_to_window(var->mlx, var->win,	var->bg.img, var->e[i].y * 80, var->e[i].x * 80);
			var->map->tab[var->pos_ennemy[i].y][var->pos_ennemy[i].x] = 'K';
			// k++;
			// var->stock_keycode = A_left;
		}
		i++;
		// j = 0;
		// while (k != 0 && i <= 100000)
		// {
		// 	i++;
		// 	if (i == 100000)
		// 		var->stock_keycode = D_right;
		// }
	}
	
}