/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:30:05 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/16 13:45:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var		var;

	if (argc != 2)
		return (1);
	var.mlx = mlx_init();
	var.win = NULL;
	init_var(&var);
	init_santa(&var);
	if (init_map(&var) == 1)
		return (1);
	if (check_rectangular(argv, &var) == 1)
	{
		free_all(&var);
		return (1);
	}
	var.santa.x = var.santa.x * 80;
	var.santa.y = var.santa.y * 80;
	var.win = mlx_new_window(var.mlx, 80 * (var.map->width + 1),
			80 * (var.map->height), "Santa!");
	mlx_expose_hook(var.win, print_map, &var);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_hook(var.win, DestroyNotify, KeyReleaseMask, exit_game, &var);
	mlx_loop(var.mlx);
	return (0);
}
