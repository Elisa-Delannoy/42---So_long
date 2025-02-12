/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:27 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/12 15:46:28 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	stock_img(t_vars *vars)
{
	vars->BG = malloc(sizeof(t_img));
	if (vars->BG == NULL)
		return (1);
	vars->player = malloc(sizeof(t_img));
		if (vars->player == NULL)
		return (1);
	vars->collect = malloc(sizeof(t_img));
		if (vars->collect == NULL)
		return (1);
	vars->exit = malloc(sizeof(t_img));
		if (vars->exit == NULL)
		return (1);
	vars->wall = malloc(sizeof(t_img));
		if (vars->exit == NULL)
		return (1);
	vars->wall->img = mlx_xpm_file_to_image(vars->mlx, "./images/wallbis1.xpm", &vars->wall->width, &vars->wall->height);
	vars->BG->img = mlx_xpm_file_to_image(vars->mlx, "./images/snowBG.xpm", &vars->BG->width, &vars->BG->height);
	vars->collect->img = mlx_xpm_file_to_image(vars->mlx, "./images/present.xpm", &vars->collect->width, &vars->collect->height);
	vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_R.xpm", &vars->player->width, &vars->player->height);
	vars->exit->img = mlx_xpm_file_to_image(vars->mlx, "./images/exit.xpm", &vars->exit->width, &vars->exit->height);
	return (0);
}

void	print_map(t_map *map, t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->i = 0;
	map->j = 0;
	stock_img(vars);
	while (map->tab[map->i])
	{
		while (map->tab[map->i][map->j])
		{
			if (map->tab[map->i][map->j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->BG->img, x, y);
			if (map->tab[map->i][map->j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall->img, x, y);
			if (map->tab[map->i][map->j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collect->img, x, y);
			if (map->tab[map->i][map->j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player->img, x, y);
			if (map->tab[map->i][map->j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit->img, x, y);
			map->j++;
			x = x + 80;
		}
		y = y + 80;
		x = 0;
		map->j = 0;
		map->i++;
	}
}

int	init_santa(t_vars *vars)
{
	vars->santa = malloc(sizeof(t_player));
	if (!vars->santa)
		return (1);
	vars->santa->x = 0;
	vars->santa->y = 0;
	vars->prev_keycode = D_right; /*init vars pas init santa et voir s il faut aussi malloc vars*/
	vars->prev_keycode_LR = D_right; /*init vars pas init santa et voir s il faut aussi malloc vars*/
	return (0);
}

void	img_new_event(int keycode, t_vars *vars)
{
	if (keycode == D_right)
		vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_R.xpm", &vars->player->width, &vars->player->height);
	if (keycode == A_left)
		vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_L.xpm", &vars->player->width, &vars->player->height);
	if (keycode == W_top)
	{
		/*refaire une image : si left, top left*/
		// if (vars->img->prev_keycode == S_left || (vars->img->prev_keycode == W_bottom && vars->img->prev_keycode_LR == S_left))
		// 	image top left
		vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_T.xpm", &vars->player->width, &vars->player->height);
	}
	if (keycode == S_bottom)
	{
		if (vars->prev_keycode_LR == D_right) 
			vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_R.xpm", &vars->player->width, &vars->player->height);
		else
			vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_L.xpm", &vars->player->width, &vars->player->height);
	}
	// mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player->img, vars->santa->x, vars->santa->y);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == D_right)
	{
		vars->santa->x += 80;
		vars->prev_keycode_LR = D_right;
	}
	if (keycode == A_left)
	{
		vars->santa->x -= 80;
		vars->prev_keycode_LR = A_left;
	}
	if (keycode == W_top)
		vars->santa->y -= 80;
	if (keycode == S_bottom)
		vars->santa->y += 80;
	if (keycode == ESC)
		mlx_destroy_window(vars->mlx, vars->win);  /*voir pour les free*/
	vars->prev_keycode = keycode;
	img_new_event(keycode, vars);
	return (0);
}
