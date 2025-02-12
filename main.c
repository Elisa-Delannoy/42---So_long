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
	t_vars		vars;
	t_map	map;
	(void)	argc;


	vars.mlx = mlx_init();
	if (init_santa(&vars) == 1)
		return (1);
	check_rectangular(argv, &map, &vars);
	vars.win = mlx_new_window(vars.mlx, 80 * (map.width + 1), 80 * map.height, "Santa!");
	print_map(&map, &vars);
	// vars.img->img = mlx_xpm_file_to_image(vars.mlx, "./images/santa_R.xpm", &vars.img->width, &vars.img->height);
	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, vars.santa->x, vars.santa->y);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	free (vars.santa);
	
	return (0);
}

