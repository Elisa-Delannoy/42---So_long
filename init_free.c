/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:26:34 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/17 11:26:35 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_santa(t_var *var)
{
	var->santa.x = 0;
	var->santa.y = 0;
	return (0);
}

int	init_map(t_var *var)
{
	var->map = malloc(sizeof(t_map));
	if (var->map == NULL)
		return (1);
	var->map->i = -1;
	var->map->j = 0;
	var->map->e = 0;
	var->map->p = 0;
	var->map->c = 0;
	var->map->c2 = 0;
	var->map->tab = NULL;
	var->map->height = 80;
	var->map->width = 80;
	var->map->count = 0;
	var->map->move = 0;
	var->map->printmove = "0";
	return (0);
}

void	init_var(t_var *var)
{
	int	i;

	var->prev_keycode_lr = D_right;
	var->bg.img = NULL;
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
	var->mapexit.x = 0;
	var->mapexit.y = 0;
}

void	free_img(t_var *var)
{
	int	i;

	if (var->collect.img)
		mlx_destroy_image(var->mlx, var->collect.img);
	i = -1;
	while (++i < 3)
	{
		if (var->exit[i].img)
			mlx_destroy_image(var->mlx, var->exit[i].img);
	}
	if (var->wall[0].img)
		mlx_destroy_image(var->mlx, var->wall[0].img);
	if (var->wall[1].img)
		mlx_destroy_image(var->mlx, var->wall[1].img);
	if (var->bg.img)
		mlx_destroy_image(var->mlx, var->bg.img);
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
	if (var->map)
		free(var->map);
	free_img(var);
	if (var->win)
		mlx_destroy_window(var->mlx, var->win);
	if (var->mlx)
	{
		mlx_destroy_display(var->mlx);
		free(var->mlx);
	}
}
