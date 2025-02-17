/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:27 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/16 13:16:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	stock_img_2(t_var *var)
{
	var->collect.img = mlx_xpm_file_to_image(var->mlx, "./images/present.xpm",
			&var->collect.width, &var->collect.height);
	var->exit[0].img = mlx_xpm_file_to_image(var->mlx, "./images/exit.xpm",
			&var->exit[0].width, &var->exit[0].height);
	var->exit[1].img = mlx_xpm_file_to_image(var->mlx, "./images/exit_1.xpm",
			&var->exit[1].width, &var->exit[1].height);
	var->exit[2].img = mlx_xpm_file_to_image(var->mlx, "./images/exit_2.xpm",
			&var->exit[2].width, &var->exit[2].height);
	return (0);
}

int	stock_img(t_var *var)
{
	var->wall[0].img = mlx_xpm_file_to_image(var->mlx, "./images/wall.xpm",
			&var->wall[0].width, &var->wall[0].height);
	var->wall[1].img = mlx_xpm_file_to_image(var->mlx, "./images/trees.xpm",
			&var->wall[1].width, &var->wall[1].height);
	var->bg.img = mlx_xpm_file_to_image(var->mlx,
			"./images/snowBG.xpm", &var->bg.width, &var->bg.height);
	var->p[0].img = mlx_xpm_file_to_image(var->mlx, "./images/santaR"
			".xpm", &var->p[0].width, &var->p[0].height);
	var->p[1].img = mlx_xpm_file_to_image(var->mlx, "./images/santaL"
			".xpm", &var->p[1].width, &var->p[1].height);
	var->p[2].img = mlx_xpm_file_to_image(var->mlx, "./images/"
			"santa_T.xpm", &var->p[2].width, &var->p[2].height);
	var->p[3].img = mlx_xpm_file_to_image(var->mlx, "./images/"
			"santa_T_L.xpm", &var->p[3].width, &var->p[3].height);
	var->p[4].img = mlx_xpm_file_to_image(var->mlx, "./images/santa_"
			"present_R.xpm", &var->p[4].width, &var->p[4].height);
	var->p[5].img = mlx_xpm_file_to_image(var->mlx, "./images/santa"
			"_present_L.xpm", &var->p[5].width, &var->p[4].height);
	stock_img_2(var);
	return (0);
}

void	put_image(t_var *var, int x, int y)
{
	if (var->map->tab[var->map->i][var->map->j] == '0')
		mlx_put_image_to_window(var->mlx, var->win, var->bg.img, x, y);
	if ((var->map->i == 0 || var->map->i == map_height(var) - 1
			|| var->map->j == 0 || var->map->j == ft_strlen(var->map->tab
				[var->map->i]) - 1) && var->map->tab[var->map->i]
		[var->map->j] == '1')
		mlx_put_image_to_window(var->mlx, var->win, var->wall->img, x, y);
	else if (var->map->tab[var->map->i][var->map->j] == '1')
		mlx_put_image_to_window(var->mlx, var->win, var->wall[1].img, x, y);
	if (var->map->tab[var->map->i][var->map->j] == 'C')
		mlx_put_image_to_window(var->mlx, var->win, var->collect.img, x, y);
	if (var->map->tab[var->map->i][var->map->j] == 'P')
		mlx_put_image_to_window(var->mlx, var->win,
			var->p[0].img, x, y);
	if (var->map->tab[var->map->i][var->map->j] == 'E')
	{
		var->mapexit.x = x;
		var->mapexit.y = y;
		mlx_put_image_to_window(var->mlx, var->win, var->exit[0].img, x, y);
	}
}

int	print_map(t_var *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	var->map->i = 0;
	var->map->j = 0;
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
