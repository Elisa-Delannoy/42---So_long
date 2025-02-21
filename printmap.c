/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:27 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/21 15:59:04 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_ennemy(t_var *var, int x, int y)
{
	mlx_put_image_to_window(var->mlx, var->win, var->ennemy.img, x, y);
	if (var->map->m > 0)
	{
		var->e[var->map->m - 1].x = y / 80;
		var->e[var->map->m - 1].y = x / 80;
		var->pos_en[var->map->m - 1].x = x / 80;
		var->pos_en[var->map->m - 1].y = y / 80;
		var->map->m--;
	}
}

void	put_image(t_var *var, int x, int y)
{
	if (var->map->tab[var->map->i][var->map->j] == '0')
		mlx_put_image_to_window(var->mlx, var->win, var->bg.img, x, y);
	if ((var->map->i == 0 || var->map->i == map_height(var) - 1
			|| var->map->j == 0 || var->map->j == ft_strlen(var->map->tab
				[var->map->i]) - 1) && var->map->tab[var->map->i]
		[var->map->j] == '1')
		mlx_put_image_to_window(var->mlx, var->win, var->wall[0].img, x, y);
	else if (var->map->tab[var->map->i][var->map->j] == '1')
		mlx_put_image_to_window(var->mlx, var->win, var->wall[1].img, x, y);
	if (var->map->tab[var->map->i][var->map->j] == 'C')
		mlx_put_image_to_window(var->mlx, var->win, var->collect.img, x, y);
	if (var->map->tab[var->map->i][var->map->j] == 'P')
		mlx_put_image_to_window(var->mlx, var->win,
			var->p_a[0][var->i].img, x, y);
	if (var->map->tab[var->map->i][var->map->j] == 'E')
	{
		var->mapexit.x = x;
		var->mapexit.y = y;
		mlx_put_image_to_window(var->mlx, var->win, var->exit[0].img, x, y);
	}
	if (var->map->tab[var->map->i][var->map->j] == 'M')
		put_image_ennemy(var, x, y);
}

void	init_printmap(t_var *var)
{
	var->map->i = 0;
	var->map->j = 0;
	var->e = malloc((var->map->m + 1) * sizeof(t_player));
	var->pos_en = malloc((var->map->m + 1) * sizeof(t_player));
	var->e[var->map->m].x = '\0';
	var->e[var->map->m].y = '\0';
	var->pos_en[var->map->m].x = '\0';
	var->pos_en[var->map->m].y = '\0';
}

int	print_map(t_var *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	init_printmap(var);
	stock_img(var);
	while (var->map->tab[var->map->i])
	{
		while (var->map->tab[var->map->i][var->map->j])
		{
			put_image(var, x, y);
			var->map->j++;
			x = x + 80;
		}
		y = y + 80;
		x = 0;
		var->map->j = 0;
		var->map->i++;
	}
	mlx_string_put(var->mlx, var->win, 160, 30, 0xFFFFFF, "movement :");
	mlx_string_put(var->mlx, var->win, 240, 30, 0xFFFFFF, var->map->printmove);
	return (0);
}
