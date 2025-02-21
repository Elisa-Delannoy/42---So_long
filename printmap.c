/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:27 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/20 20:05:30 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	stock_img_2(t_var *var)
{
	var->p_a[0][0].img = mlx_xpm_file_to_image(var->mlx, "./images/santaR0"
			".xpm", &var->p_a[0][0].width, &var->p_a[0][0].height);
	var->p_a[0][1].img = mlx_xpm_file_to_image(var->mlx, "./images/santaR1"
			".xpm", &var->p_a[0][1].width, &var->p_a[0][1].height);
	var->p_a[0][2].img = mlx_xpm_file_to_image(var->mlx, "./images/santaR3"
			".xpm", &var->p_a[0][2].width, &var->p_a[0][2].height);
	var->p_a[0][3].img = mlx_xpm_file_to_image(var->mlx, "./images/santaR1"
		".xpm", &var->p_a[0][3].width, &var->p_a[0][3].height);			
	var->p_a[1][0].img = mlx_xpm_file_to_image(var->mlx, "./images/santaL0"
			".xpm", &var->p_a[1][0].width, &var->p_a[1][0].height);
	var->p_a[1][1].img = mlx_xpm_file_to_image(var->mlx, "./images/santaL1"
			".xpm", &var->p_a[1][1].width, &var->p_a[1][1].height);
	var->p_a[1][2].img = mlx_xpm_file_to_image(var->mlx, "./images/santaL3"
			".xpm", &var->p_a[1][2].width, &var->p_a[1][2].height);
	var->p_a[1][3].img = mlx_xpm_file_to_image(var->mlx, "./images/santaL1"
		".xpm", &var->p_a[1][3].width, &var->p_a[1][3].height);
	var->pp_a[0][0].img = mlx_xpm_file_to_image(var->mlx, "./images/santa_"
			"present_R.xpm", &var->pp_a[0][0].width, &var->pp_a[0][0].height);
	var->pp_a[0][1].img = mlx_xpm_file_to_image(var->mlx, "./images/santa_"
			"present_L.xpm", &var->pp_a[0][1].width, &var->pp_a[0][1].height);
	// var->pp_a[0][2].img = mlx_xpm_file_to_image(var->mlx, "./images/santa_"
	// 		"present_R.xpm", &var->pp_a[0][2].width, &var->pp_a[0][2].height);	
	// var->pp_a[0][3].img = mlx_xpm_file_to_image(var->mlx, "./images/santa_"
	// 		"present_L.xpm", &var->pp_a[0][3].width, &var->pp_a[0][3].height);
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
	var->collect.img = mlx_xpm_file_to_image(var->mlx, "./images/present.xpm",
			&var->collect.width, &var->collect.height);
	var->exit[0].img = mlx_xpm_file_to_image(var->mlx, "./images/exit.xpm",
			&var->exit[0].width, &var->exit[0].height);
	var->exit[1].img = mlx_xpm_file_to_image(var->mlx, "./images/exit_1.xpm",
			&var->exit[1].width, &var->exit[1].height);
	var->exit[2].img = mlx_xpm_file_to_image(var->mlx, "./images/exit_2.xpm",
			&var->exit[2].width, &var->exit[2].height);
	var->p[0].img = mlx_xpm_file_to_image(var->mlx, "./images/"
			"santa_T.xpm", &var->p[0].width, &var->p[0].height);
	var->p[1].img = mlx_xpm_file_to_image(var->mlx, "./images/"
			"santa_T_L.xpm", &var->p[1].width, &var->p[1].height);
	var->pp_a[1][0].img = mlx_xpm_file_to_image(var->mlx, "./images/santa_"
			"present_L.xpm", &var->pp_a[1][0].width, &var->pp_a[1][0].height);
	var->pp_a[1][1].img = mlx_xpm_file_to_image(var->mlx, "./images/santa_"
			"present_R.xpm", &var->pp_a[1][1].width, &var->pp_a[1][1].height);
	var->ennemy.img = mlx_xpm_file_to_image(var->mlx, "./images/ennemy.xpm",
			&var->ennemy.width, &var->ennemy.height);
	var->dead[0].img = mlx_xpm_file_to_image(var->mlx, "./images/deadR.xpm",
		&var->dead[0].width, &var->dead[0].height);
	var->dead[1].img = mlx_xpm_file_to_image(var->mlx, "./images/deadL.xpm",
		&var->dead[1].width, &var->dead[1].height);
	var->santa_fight[0].img = mlx_xpm_file_to_image(var->mlx, "./images/fight_R"
		".xpm", &var->santa_fight[0].width, &var->santa_fight[0].height);
	var->santa_fight[1].img = mlx_xpm_file_to_image(var->mlx, "./images/fight_L"
		".xpm", &var->santa_fight[1].width, &var->santa_fight[1].height);
	var->santa_fight[2].img = mlx_xpm_file_to_image(var->mlx, "./images/fight_T"
		".xpm", &var->santa_fight[2].width, &var->santa_fight[2].height);
	var->santa_fight[3].img = mlx_xpm_file_to_image(var->mlx, "./images/fight_b"
		".xpm", &var->santa_fight[3].width, &var->santa_fight[3].height);
			
	// var->pp_a[1][2].img = mlx_xpm_file_to_image(var->mlx, "./images/santa_"
	// 	"present_L.xpm", &var->pp_a[1][2].width, &var->pp_a[1][2].height);
	// var->pp_a[1][3].img = mlx_xpm_file_to_image(var->mlx, "./images/santa_"
	// 	"present_R.xpm", &var->pp_a[1][3].width, &var->pp_a[1][3].height);
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
	{
		mlx_put_image_to_window(var->mlx, var->win, var->ennemy.img, x, y);
		// printf("%d\n", x / 80);
		// printf("%d\n", y / 80);
		// printf("map m %d\n",var->map->m );
		// printf("%d\n", var->e[10].x);
		if (var->map->m > 0)
		{
			var->e[var->map->m - 1].x = y / 80;
			var->e[var->map->m - 1].y = x / 80;
			var->pos_en[var->map->m - 1].x = x / 80;
			var->pos_en[var->map->m - 1].y = y / 80;
		// 	printf("y %d\n", var->e[0].y);
		// printf("x %d\n", var->e[0].x);
			var->map->m--;
		}
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
	var->e = malloc((var->map->m + 1) * sizeof(t_player));
	var->pos_en = malloc((var->map->m + 1) * sizeof(t_player));
	var->e[var->map->m].x = '\0';
	var->e[var->map->m].y = '\0';
	var->pos_en[var->map->m].x = '\0';
	var->pos_en[var->map->m].y = '\0';
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
	// printf("x0 =%d\n", var->pos_en[0].x);
	// printf("y0 =%d\n", var->pos_en[0].y);
	// printf("x1 =%d\n", var->pos_en[1].x);
	// printf("y1 =%d\n", var->pos_en[1].y);
	mlx_string_put(var->mlx, var->win, 160, 30, 0xFFFFFF, "movement :");
	mlx_string_put(var->mlx, var->win, 240, 30, 0xFFFFFF, var->map->printmove);
	return (0);
}
