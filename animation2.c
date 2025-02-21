/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:42:01 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/21 15:03:15 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dead(t_var *var, size_t i)
{
	if (var->e[i].y == (var->santa.x / 80) && var->e[i].x == (var->santa.y / 80)
		&& var->map->tab[var->pos_en[i].y][var->pos_en[i].x] == 'M')
	{
		if (var->stock_keycode == A_left || var->prev_keycode_lr == A_left)
			mlx_put_image_to_window(var->mlx, var->win, var->dead[1].img,
				var->santa.x, var->santa.y);
		else
			mlx_put_image_to_window(var->mlx, var->win, var->dead[0].img,
				var->santa.x, var->santa.y);
		if (var->map->tab[var->santa.y / 80][var->santa.x / 80] != 'D')
			var->i_wait_dead = 1;
		var->map->tab[var->pos_en[i].y][var->pos_en[i].x] = 'D';
		var->map->tab[var->santa.y / 80][var->santa.x / 80] = 'D';
		if (var->i_wait_dead == 1)
			exit_game(var);
	}
}

void	move_ennemy(t_var *var, size_t i)
{
	if (var->map->tab[var->e[i].x][var->e[i].y] == '2')
		var->map->tab[var->e[i].x][var->e[i].y] = '0';
	if (var->map->tab[var->pos_en[i].y][var->pos_en[i].x] == 'M')
	{
		if (var->map->tab[var->e[i].x + 1][var->e[i].y] == '0')
			var->e[i].x = var->e[i].x + 1;
		else if (var->map->tab[var->e[i].x][var->e[i].y + 1] == '0')
			var->e[i].y = var->e[i].y + 1;
		else if (var->map->tab[var->e[i].x][var->e[i].y - 1] == '0')
			var->e[i].y = var->e[i].y - 1;
		else if (var->map->tab[var->e[i].x - 1][var->e[i].y] == '0')
			var->e[i].x = var->e[i].x - 1;
	}
	if (var->map->tab[var->pos_en[i].y][var->pos_en[i].x] != 'K')
		var->map->tab[var->e[i].x][var->e[i].y] = '2';
}

void	ennemies_anim(t_var *var, int i)
{
	while (var->e[i].x != 0 && (var->map->tab[var->pos_en[i].y]
			[var->pos_en[i].x] == 'M' || var->map->tab[var->pos_en[i].y]
			[var->pos_en[i].x] == 'K'))
	{
		if (var->i_loop == 0)
		{
			if (var->e[i].y != var->santa.x / 80 || var->e[i].x
				!= var->santa.y / 80)
				mlx_put_image_to_window(var->mlx, var->win, var->bg.img,
					var->e[i].y * 80, var->e[i].x * 80);
			move_ennemy(var, i);
			if (var->map->tab[var->pos_en[i].y][var->pos_en[i].x] != 'K')
				mlx_put_image_to_window(var->mlx, var->win, var->ennemy.img,
					var->e[i].y * 80, var->e[i].x * 80);
			else if (var->map->tab[var->pos_en[i].y][var->pos_en[i].x] == 'K'
				&& (var->e[i].y != var->santa.x / 80 || var->e[i].x
				!= var->santa.y / 80))
				mlx_put_image_to_window(var->mlx, var->win, var->bg.img,
					var->e[i].y * 80, var->e[i].x * 80);
		}
		dead(var, i);
		i++;
	}
}

int	check_killed(t_var *var, int i)
{
	int	j;

	j = -1;
	if (var->map->tab[var->pos_en[i].y][var->pos_en[i].x] == 'M'
			|| var->i_wait_fight > 0)
	{
		if (var->e[i].y - 1 == var->santa.x / 80 && var->e[i].x
			== var->santa.y / 80)
			j = 0;
		else if (var->e[i].y + 1 == var->santa.x / 80 && var->e[i].x
			== var->santa.y / 80)
			j = 1;
		else if (var->e[i].y == var->santa.x / 80 && var->e[i].x + 1
			== var->santa.y / 80)
			j = 2;
		else if (var->e[i].y == var->santa.x / 80 && var->e[i].x - 1
			== var->santa.y / 80)
			j = 3;
	}
	return (j);
}

void	kill_ennemy(t_var *var, int i)
{
	int	j;

	while (var->e[i].x != 0 && var->stock_keycode == Q_kill)
	{
		j = check_killed(var, i);
		if (j != -1)
		{
			if (var->i_wait_fight == 0)
			{
				var->i_wait_fight = 1;
				var->map->tab[var->pos_en[i].y][var->pos_en[i].x] = 'K';
				var->map->tab[var->santa.y / 80][var->santa.x / 80] = 'W';
				mlx_put_image_to_window(var->mlx, var->win,
					var->santa_fight[j].img, var->santa.x, var->santa.y);
				mlx_put_image_to_window(var->mlx, var->win, var->bg.img,
					var->e[i].y * 80, var->e[i].x * 80);
			}
			if (var->i_wait_fight == 2)
				var->map->tab[var->santa.y / 80][var->santa.x / 80] = '0';
		}
		i++;
	}
}
