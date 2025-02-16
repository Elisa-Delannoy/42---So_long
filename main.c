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


int	init_map(t_var *var)
{
	var->map = malloc(sizeof(t_map));
	if (var->map == NULL)
		return (1);
	var->map->i = 0;
	var->map->j = 0;
	var->map->e = 0;
	var->map->p = 0;
	var->map->c = 0;
	var->map->c2 = 0;
	var->map->tab = NULL;
	var->map->height  = 80;
	var->map->width = 80;
	var->map->count = 0;
	var->map->move = 0;
	var->map->printmove = "0";
	return (0);
}

void	init_var(t_var *var)
{
	int	i;

	var->prev_keycode_LR = D_right;
	var->BG.img = NULL;
	i = -1;
	while (++i < 6)
		var->p[i].img = NULL;
	var->collect.img = NULL;
	i = -1;
	while (++i < 3)
		var->exit[i].img = NULL;
	i = -1;
	while (++i < 2)
		var->wall[i].img = NULL;

	// var.mapexit.x = 0;
	// var.mapexit.y = 0;
}

void	free_img(t_var *var)
{
	int	i;

	if (var->collect.img)
		mlx_destroy_image(var->mlx, var->collect.img);
	i = -1;
	while (++i < 3)
	{
		if (var->exit[i].img )
			mlx_destroy_image(var->mlx, var->exit[i].img);
	}
	if (var->wall[0].img)
		mlx_destroy_image(var->mlx, var->wall[0].img);
	if (var->wall[1].img)
		mlx_destroy_image(var->mlx, var->wall[1].img);
	if (var->BG.img)
		mlx_destroy_image(var->mlx, var->BG.img);
	i = -1;
	while (++i < 6)
	{
		if (var->p[i].img)
			mlx_destroy_image(var->mlx, var->p[i].img);
	}
}

void	free_all(t_var *var)
{
	
	if (var->map->tab)
		free_tab(var->map->tab);
	// if (var->map->move != 0 && var->map->printmove)
	// 	free(var->map->printmove);
	if (var->map)
		free(var->map);
	// if (var.santa)
	// 	free(var.santa);
	free_img(var);
	if (var->win)
		mlx_destroy_window(var->mlx, var->win);
	
	if (var->mlx)
	{
		mlx_destroy_display(var->mlx);
		free(var->mlx);
	}
}

int	main(int argc, char **argv)
{
	t_var		var;

	if (argc != 2)
		return (1);
	// if (init_var(&var) == 1)
	// 	return (1);
	
	
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
	// var.win = mlx_new_window(var.mlx, 80 * (var.map->width + 1), 80 * (var.map->height), "Santa!");
	var.win = mlx_new_window(var.mlx, 1040,400, "Santa!");
	// printf("open");
	mlx_expose_hook(var.win, print_map, &var);
	// printf("printmpa");
	mlx_key_hook(var.win, key_hook, &var);
	// printf("afterkeyhook");
	mlx_hook(var.win, DestroyNotify, KeyReleaseMask, exit_game, &var);
	mlx_loop(var.mlx);
	// free_all(&var);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_var		*var;

// 	if (argc != 2)
// 		return (1);
// 	// if (init_var(&var) == 1)
// 	// 	return (1);
	
// 	var = malloc(sizeof(t_var));
// 	var->mlx = mlx_init();
// 	var->win = NULL;
// 	init_var(var);
// 	init_santa(var);
// 	if (init_map(var) == 1)
// 		return (1);
// 	if (check_rectangular(argv, var) == 1)
// 	{
// 		free_all(var);
// 		return (1);
// 	}
// 	// var.win = mlx_new_window(var.mlx, 80 * (var.map->width + 1), 80 * (var.map->height), "Santa!");
// 	var->win = mlx_new_window(var->mlx, 1040,400, "Santa!");
// 	// printf("open");
// 	mlx_expose_hook(var->win, print_map,var);
// 	// printf("printmpa");
// 	mlx_key_hook(var->win, key_hook, var);
// 	// printf("afterkeyhook");
// 	mlx_hook(var->win, DestroyNotify, KeyReleaseMask, exit_game, var);
// 	mlx_loop(var->mlx);
// 	// free_all(&var);
// 	return (0);

