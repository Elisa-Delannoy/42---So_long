/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:30:05 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/21 15:50:35 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_i(t_var *var)
{
	if (var->i_loop == 0)
		var->i++;
	if (var->i > 3)
		var->i = 0;
	if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'T')
	{
		if (var->i > 1)
			var->i = 0;
	}
}

int	loop_hook(t_var *var)
{
	var->i_loop = (var->i_loop + 1) % 10000;
	if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'W'
		&& var->i_loop == 0)
	{
		kill_ennemy(var, 0);
		var->i_wait_fight++;
	}
	else if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'D'
		&& var->i_loop == 0)
	{
		exit_game(var);
		var->i_wait_dead++;
	}
	else if (var->map->tab[var->santa.y / 80][var->santa.x / 80] != 'D'
		&& var->map->tab[var->santa.y / 80][var->santa.x / 80] != 'W')
	{
		loop_i(var);
		santa_anim(var, var->santa.x, var->santa.y);
		ennemies_anim(var, 0);
		kill_ennemy(var, 0);
	}
	return (0);
}

int	init_main(t_var *var)
{
	init_var(var);
	init_santa(var);
	if (init_map(var) == 1)
	{
		free_all(var);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc != 2)
		return (1);
	var.mlx = mlx_init();
	var.win = NULL;
	if (init_main(&var) == 1)
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
	mlx_loop_hook(var.mlx, loop_hook, &var);
	mlx_loop(var.mlx);
	return (0);
}
