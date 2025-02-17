/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:27 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/16 13:16:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_var *var)
{
	free_all(var);
	exit (0);
}

int	img_event_exit(t_var *var)
{
	if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'E'
		&& var->map->c == 0)
		exit_game(var);
	if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'E' &&
		var->map->c <= var->map->c2)
		mlx_put_image_to_window(var->mlx, var->win, var->exit[1].img,
			var->santa.x, var->santa.y);
	else if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'E'
		&& var->map->c > var->map->c2)
		mlx_put_image_to_window(var->mlx, var->win, var->exit[0].img,
			var->santa.x, var->santa.y);
	else
		mlx_put_image_to_window(var->mlx, var->win, var->bg.img, var->santa.x,
			var->santa.y);
	return (0);
}

int	img_event_collectible(int keycode, t_var *var)
{
	if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'C')
	{
		var->map->tab[var->santa.y / 80][var->santa.x / 80] = '0';
		if (keycode == A_left || var->prev_keycode_lr == A_left)
			mlx_put_image_to_window(var->mlx, var->win, var->p[5].img,
				var->santa.x, var->santa.y);
		else
			mlx_put_image_to_window(var->mlx, var->win, var->p[4].img,
				var->santa.x, var->santa.y);
		var->map->c--;
		if (var->map->c == 0)
			mlx_put_image_to_window(var->mlx, var->win, var->exit[2].img,
				var->mapexit.x, var->mapexit.y);
		else if (var->map->c <= var->map->c2)
			mlx_put_image_to_window(var->mlx, var->win, var->exit[1].img,
				var->mapexit.x, var->mapexit.y);
		return (0);
	}
	img_event_exit(var);
	return (1);
}

void	img_new_event(int keycode, t_var *var, int x, int y)
{
	if (img_event_collectible(keycode, var) == 1)
	{
		if (keycode == D_right)
			mlx_put_image_to_window(var->mlx, var->win, var->p[0].img, x, y);
		if (keycode == A_left)
			mlx_put_image_to_window(var->mlx, var->win, var->p[1].img, x, y);
		if (keycode == W_top)
		{
			if (var->prev_keycode_lr == A_left)
				mlx_put_image_to_window(var->mlx, var->win, var->p[3].img,
					x, y);
			else
				mlx_put_image_to_window(var->mlx, var->win, var->p[2].img,
					x, y);
		}
		else if (keycode == S_bottom)
		{
			if (var->prev_keycode_lr == D_right)
				mlx_put_image_to_window(var->mlx, var->win, var->p[0].img,
					x, y);
			else
				mlx_put_image_to_window(var->mlx, var->win, var->p[1].img,
					x, y);
		}
	}
}
