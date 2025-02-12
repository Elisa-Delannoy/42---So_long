/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:30:05 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/11 20:54:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_santa(t_vars *vars)
{
	vars->santa = malloc(sizeof(t_player));
	if (!vars->santa)
		return (1);
	vars->santa->x = 0;
	vars->santa->y = 0;
	vars->img->prev_keycode = D_right; /*init vars pas init santa  et voir s il faut aussi malloc vars*/
	vars->img->prev_keycode_LR = D_right; /*init vars pas init santa et voir s il faut aussi malloc vars*/
	return (0);
}

void	img_new_event(int keycode, t_vars *vars)
{
	if (keycode == D_right)
		vars->img->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_R.xpm", &vars->img->width, &vars->img->height);
	if (keycode == A_left)
		vars->img->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_L.xpm", &vars->img->width, &vars->img->height);
	if (keycode == W_top)
	{
		/*refaire une image : si left, top left*/
		// if (vars->img->prev_keycode == S_left || (vars->img->prev_keycode == W_bottom && vars->img->prev_keycode_LR == S_left))
		// 	image top left
		vars->img->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_T.xpm", &vars->img->width, &vars->img->height);
	}
	if (keycode == S_bottom)
	{
		if (vars->img->prev_keycode_LR == D_right) 
			vars->img->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_R.xpm", &vars->img->width, &vars->img->height);
		else
			vars->img->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_L.xpm", &vars->img->width, &vars->img->height);
	}
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->santa->x, vars->santa->y);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == D_right)
	{
		vars->santa->x += 80;
		vars->img->prev_keycode_LR = D_right;
	}
	if (keycode == A_left)
	{
		vars->santa->x -= 80;
		vars->img->prev_keycode_LR = A_left;
	}
	if (keycode == W_top)
		vars->santa->y -= 80;
	if (keycode == S_bottom)
		vars->santa->y += 80;
	if (keycode == ESC)
		mlx_destroy_window(vars->mlx, vars->win);  /*voir pour les free*/
	vars->img->prev_keycode = keycode;
	img_new_event(keycode, vars);
	return (0);
}
int	main(int argc, char **argv)
{
	// t_vars		vars;
	t_map	map;
	(void)	argc;
	
	check_rectangular(argv, &map);

	
	// vars.mlx = mlx_init();
	// if (init_santa(&vars) == 1)
	// 	return (1);
	// vars.win = mlx_new_window(vars.mlx, 640, 480, "Santa!");
	// vars.img->img = mlx_xpm_file_to_image(vars.mlx, "./images/santa_R.xpm", &vars.img->width, &vars.img->height);
	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, vars.santa->x, vars.santa->y);
	// mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_loop(vars.mlx);
	// free (vars.santa);
	
	return (0);
}

