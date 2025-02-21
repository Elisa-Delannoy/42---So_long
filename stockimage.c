/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockimage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:27 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/21 16:03:25 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	stock_img_3(t_var *var)
{
	var->santa_fight[0].img = mlx_xpm_file_to_image(var->mlx, "./images/fight_R"
			".xpm", &var->santa_fight[0].width, &var->santa_fight[0].height);
	var->santa_fight[1].img = mlx_xpm_file_to_image(var->mlx, "./images/fight_L"
			".xpm", &var->santa_fight[1].width, &var->santa_fight[1].height);
	var->santa_fight[2].img = mlx_xpm_file_to_image(var->mlx, "./images/fight_T"
			".xpm", &var->santa_fight[2].width, &var->santa_fight[2].height);
	var->santa_fight[3].img = mlx_xpm_file_to_image(var->mlx, "./images/fight_b"
			".xpm", &var->santa_fight[3].width, &var->santa_fight[3].height);
	var->ennemy.img = mlx_xpm_file_to_image(var->mlx, "./images/ennemy.xpm",
			&var->ennemy.width, &var->ennemy.height);
	return (0);
}

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
	var->pp_a[1][0].img = mlx_xpm_file_to_image(var->mlx, "./images/santa_"
			"present_L.xpm", &var->pp_a[1][0].width, &var->pp_a[1][0].height);
	var->pp_a[1][1].img = mlx_xpm_file_to_image(var->mlx, "./images/santa_"
			"present_R.xpm", &var->pp_a[1][1].width, &var->pp_a[1][1].height);
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
	var->dead[0].img = mlx_xpm_file_to_image(var->mlx, "./images/deadR.xpm",
			&var->dead[0].width, &var->dead[0].height);
	var->dead[1].img = mlx_xpm_file_to_image(var->mlx, "./images/deadL.xpm",
			&var->dead[1].width, &var->dead[1].height);
	stock_img_2(var);
	stock_img_3(var);
	return (0);
}
