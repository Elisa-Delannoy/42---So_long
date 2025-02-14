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


int	init_map(t_var *var)
{
	var->map = malloc(sizeof(t_map));
	if (var->map == NULL)
		return (1);
	var->map->count = 0;
	var->map->move = 0;
	return (0);
}

void	free_img(t_var *var)
{
	if (var->collect.img)
		mlx_destroy_image(var->mlx, var->collect.img);
	if (var->exit[0].img )
		mlx_destroy_image(var->mlx, var->exit[0].img);
	if (var->exit[1].img)
		mlx_destroy_image(var->mlx, var->exit[1].img);
	if (var->exit[2].img)
		mlx_destroy_image(var->mlx, var->exit[2].img);
	if (var->wall[0].img)
		mlx_destroy_image(var->mlx, var->wall[0].img);
	if (var->wall[1].img)
		mlx_destroy_image(var->mlx, var->wall[1].img);
	if (var->BG.img)
		mlx_destroy_image(var->mlx, var->BG.img);
	if (var->p[0].img)
		mlx_destroy_image(var->mlx, var->p[0].img);
	if (var->p[1].img)
		mlx_destroy_image(var->mlx, var->p[1].img);
	if (var->p[2].img)
		mlx_destroy_image(var->mlx, var->p[2].img);;
	if (var->p[3].img)
		mlx_destroy_image(var->mlx, var->p[3].img);;
	if (var->p[4].img)
		mlx_destroy_image(var->mlx, var->p[4].img);
	if (var->p[5].img)
		mlx_destroy_image(var->mlx, var->p[5].img); 
	return ;
}

void	free_all(t_var var)
{

	// free_img(&var);
	if (var.win)
		mlx_destroy_window(var.mlx, var.win);
	if (var.mlx)
	{
		mlx_destroy_display(var.mlx);
		free(var.mlx);
	}
	if (var.map->tab)
		free_tab(&var, var.map->tab);
	if (var.map)
		free(var.map);
	if (var.santa)
		free(var.santa);
		
}

int	main(int argc, char **argv)
{
	t_var		var;
	
	if (argc != 2)
		return (1);
	var.mlx = mlx_init();
	var.win = NULL;
	if (init_santa(&var) == 1)
		return (1);
	if (init_map(&var) == 1)
		return (1);

	if (check_rectangular(argv, &var) == 1)
	{
		free_all(var);
		return (1);
	}
		
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

