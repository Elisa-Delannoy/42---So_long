/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:42:01 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/20 19:14:48 by edelanno         ###   ########.fr       */
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
			mlx_put_image_to_window(var->mlx, var->win,	var->pp_a[0][var->i].img, x, y);
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
	if (var->stock_keycode == W_top && var->prev_keycode_lr == D_right)
		mlx_put_image_to_window(var->mlx, var->win,	var->p[0].img, x, y);
	else if (var->stock_keycode == W_top && var->prev_keycode_lr == A_left)
		mlx_put_image_to_window(var->mlx, var->win,	var->p[1].img, x, y);
}

void	dead(t_var *var, size_t i)
{
	// printf("%c", var->map->tab[var->santa.y / 80][var->santa.x / 80]);
	// if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'D')
	// {
	// 	var->i_wait_dead++;
	// 	exit_game(var);
	// }
	if (var->e[i].y == (var->santa.x / 80) && var->e[i].x == (var->santa.y / 80)
		&& var->map->tab[var->pos_en[i].y][var->pos_en[i].x] == 'M')
	{
		if (var->stock_keycode == A_left || var->prev_keycode_lr == A_left)
				mlx_put_image_to_window(var->mlx, var->win,	var->dead[1].img,
				var->santa.x, var->santa.y);
		else
			mlx_put_image_to_window(var->mlx, var->win,	var->dead[0].img, 
			var->santa.x, var->santa.y);
		if (var->map->tab[var->pos_en[i].y][var->pos_en[i].x] != 'D')
			var->i_wait_dead = 1;
		var->map->tab[var->pos_en[i].x][var->pos_en[i].y] = 'D';
		if (var->i_wait_dead == 1)
		{
			// printf("loop %d\n", var->i_loop);
		exit_game(var);
		// printf("dead%d\n", var->i_wait_dead);
		}
	}
}

void	move_ennemy(t_var *var, size_t i)
{
	if (var->map->tab[var->e[i].x + 1][var->e[i].y ] == '0')
		var->e[i].x =var->e[i].x + 1;
	else if (var->map->tab[var->e[i].x - 1][var->e[i].y ] == '0')
		var->e[i].x =var->e[i].x - 1;
	else if (var->map->tab[var->e[i].x][var->e[i].y + 1] == '0')
		var->e[i].y = var->e[i].y + 1;
	else if (var->map->tab[var->e[i].x ][var->e[i].y - 1] == '0')
		var->e[i].y = var->e[i].y - 1;
}
void	ennemies_anim(t_var *var)
{
	int i = 0;
	
	while (var->e[i].x != 0 && (var->map->tab[var->pos_en[i].y]
		[var->pos_en[i].x] == 'M'|| var->map->tab[var->pos_en[i].y]
		[var->pos_en[i].x] == 'K'))
	{
		if (var->i_loop == 0)
		{
			if (var->e[i].y != var->santa.x / 80 || var->e[i].x 
				!= var->santa.y / 80)
				mlx_put_image_to_window(var->mlx, var->win,	var->bg.img,
				var->e[i].y * 80, var->e[i].x * 80);
			move_ennemy(var, i);
			if (var->map->tab[var->pos_en[i].y][var->pos_en[i].x] == 'M')
				mlx_put_image_to_window(var->mlx, var->win,	var->ennemy.img,
					var->e[i].y * 80, var->e[i].x * 80);		
			else if (var->map->tab[var->pos_en[i].y][var->pos_en[i].x] == 'K'
				&& (var->e[i].y != var->santa.x / 80 || var->e[i].x 
				!= var->santa.y / 80))
				mlx_put_image_to_window(var->mlx, var->win,	var->bg.img, 
				var->e[i].y * 80, var->e[i].x * 80);
		}
		dead(var, i);
		i++;
	}
}

void	kill_ennemy(t_var *var, int i)
{
	int	j;

	while (var->e[i].x != 0 && var->stock_keycode == Q_kill)
	{
		j = - 1;
		if (var->e[i].y - 1 == var->santa.x / 80 && var->e[i].x == var->santa.y / 80)
			j = 0;
		else if (var->e[i].y + 1 == var->santa.x / 80 && var->e[i].x == var->santa.y / 80)
			j = 1;
		else if (var->e[i].y == var->santa.x / 80 && var->e[i].x + 1 == var->santa.y / 80)
			j = 2;
		else if (var->e[i].y == var->santa.x / 80 && var->e[i].x - 1 == var->santa.y / 80)
			j = 3;
		if (j != - 1)
		{
			mlx_put_image_to_window(var->mlx, var->win,	var->santa_fight[j].img, var->santa.x, var->santa.y);
			mlx_put_image_to_window(var->mlx, var->win,	var->bg.img, var->e[i].y * 80, var->e[i].x * 80);
			var->map->tab[var->pos_en[i].y][var->pos_en[i].x] = 'K';
		}
		i++;
	}
}

// void	wait_after_kill
// {
// 	j = 0;
// 		while (k != 0 && i <= 100000)
// 		{
// 			i++;
// 			if (i == 100000)
// 				var->stock_keycode = D_right;
// 		}
// }