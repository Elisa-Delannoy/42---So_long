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


int	main(int argc, char **argv)
{
	t_var		var;
	// t_map	map;
	(void)	argc;


	var.mlx = mlx_init();
	if (init_santa(&var) == 1)
		return (1);
	var.map = malloc(sizeof(t_map));
	if (var.map == NULL)
		return (1);
	var.map->count = 0;
	check_rectangular(argv, &var);
	var.win = mlx_new_window(var.mlx, 80 * (var.map->width + 1), 80 * (var.map->height), "Santa!");
	mlx_expose_hook(var.win, print_map, &var);
	// var.img->img = mlx_xpm_file_to_image(var.mlx, "./images/santa_R.xpm", &var.img->width, &var.img->height);
	// mlx_put_image_to_window(var.mlx, var.win, var.img->img, var.santa->x, var.santa->y);
	// printf("tab = %c\n", var.map->tab[3][1]);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_hook(var.win, DestroyNotify, KeyReleaseMask, exit_game, &var);
	mlx_loop(var.mlx);
	free (var.santa);
	
	return (0);
}

