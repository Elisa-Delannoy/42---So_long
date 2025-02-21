/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:26:34 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/21 15:49:24 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img_loop(t_var *var, int i)
{
	while (++i < 3)
	{
		if (var->exit[i].img)
			mlx_destroy_image(var->mlx, var->exit[i].img);
		if (var->p_a[0][i].img)
			mlx_destroy_image(var->mlx, var->p_a[0][i].img);
		if (var->p_a[1][i].img)
			mlx_destroy_image(var->mlx, var->p_a[1][i].img);
		if (var->santa_fight[i].img)
			mlx_destroy_image(var->mlx, var->santa_fight[i].img);
		if (var->pp_a[0][i].img)
			mlx_destroy_image(var->mlx, var->pp_a[0][i].img);
		if (i < 2 && var->pp_a[1][i].img)
			mlx_destroy_image(var->mlx, var->pp_a[1][i].img);
		if (i < 2 && var->dead[i].img)
			mlx_destroy_image(var->mlx, var->dead[i].img);
		if (i < 2 && var->p[i].img)
			mlx_destroy_image(var->mlx, var->p[i].img);
		if (i < 2 && var->wall[i].img)
			mlx_destroy_image(var->mlx, var->wall[i].img);
		if (i < 3 && var->exit[i].img)
			mlx_destroy_image(var->mlx, var->exit[i].img);
	}
}

void	free_img(t_var *var)
{
	free_img_loop(var, -1);
	if (var->collect.img)
		mlx_destroy_image(var->mlx, var->collect.img);
	if (var->bg.img)
		mlx_destroy_image(var->mlx, var->bg.img);
	if (var->ennemy.img)
		mlx_destroy_image(var->mlx, var->ennemy.img);
	if (var->exit[0].img)
		mlx_destroy_image(var->mlx, var->exit[0].img);
	if (var->exit[1].img)
		mlx_destroy_image(var->mlx, var->exit[1].img);
	if (var->exit[2].img)
		mlx_destroy_image(var->mlx, var->exit[2].img);
}

void	free_all(t_var *var)
{
	if (var->e)
		free(var->e);
	if (var->pos_en)
		free(var->pos_en);
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
