/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:26:34 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/21 15:57:25 by edelanno         ###   ########.fr       */
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
	var->map->i = 0;
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
	var->map->m = 0;
	return (0);
}

void	init_var_img(t_var *var, int i)
{
	while (i < 4)
	{
		var->p_a[0][i].img = NULL;
		var->p_a[1][i].img = NULL;
		var->santa_fight[i].img = NULL;
		if (i < 2)
		{
			var->pp_a[0][i].img = NULL;
			var->pp_a[1][i].img = NULL;
		}
		if (i < 3)
			var->exit[i].img = NULL;
		i++;
	}
	var->collect.img = NULL;
	var->ennemy.img = NULL;
	var->dead[0].img = NULL;
	var->dead[1].img = NULL;
	var->p[0].img = NULL;
	var->p[1].img = NULL;
	var->wall[0].img = NULL;
	var->wall[1].img = NULL;
	var->bg.img = NULL;
}

void	init_var(t_var *var)
{
	var->prev_keycode_lr = D_right;
	var->stock_keycode = D_right;
	var->previous_keycode = D_right;
	var->bg.img = NULL;
	var->i_loop = 0;
	var->i = 0;
	var->i_wait_dead = 0;
	var->i_wait_fight = 0;
	var->i_count_wait = 0;
	var->mapexit.x = 0;
	var->mapexit.y = 0;
	var->pos_en = NULL;
	var->e = NULL;
	init_var_img(var, 0);
}
