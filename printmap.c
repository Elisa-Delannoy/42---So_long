/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:27 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/12 15:46:28 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	stock_img_2(t_vars *vars)
{
	vars->collect = malloc(sizeof(t_img));
	if (vars->collect == NULL)
		return (1);
	// vars->exit = malloc(3 * sizeof(t_img));
	// if (vars->exit == NULL)
	// 	return (1);
	// vars->exit1 = malloc(sizeof(t_img));
	// if (vars->exit1 == NULL)
	// 	return (1);
	// vars->exit2 = malloc(sizeof(t_img));
	// if (vars->exit2 == NULL)
	// 	return (1);
	vars->collect->img = mlx_xpm_file_to_image(vars->mlx, "./images/present.xpm", &vars->collect->width, &vars->collect->height);
	vars->exit[0].img = mlx_xpm_file_to_image(vars->mlx, "./images/exit.xpm", &vars->exit[0].width, &vars->exit[0].height);
	vars->exit[1].img = mlx_xpm_file_to_image(vars->mlx, "./images/exit_1.xpm", &vars->exit[0].width, &vars->exit[0].height);
	vars->exit[2].img = mlx_xpm_file_to_image(vars->mlx, "./images/exit_2.xpm", &vars->exit[0].width, &vars->exit[0].height);
	return (0);
}

int	stock_img(t_vars *vars)
{
	vars->BG = malloc(sizeof(t_img));
	if (vars->BG == NULL)
		return (1);
	vars->player = malloc(sizeof(t_img));
	if (vars->player == NULL)
		return (1);
	vars->wall = malloc(sizeof(t_img));
	if (vars->wall == NULL)
		return (1);
	vars->wallin = malloc(sizeof(t_img));
	if (vars->wallin == NULL)
		return (1);
	vars->wall->img = mlx_xpm_file_to_image(vars->mlx, "./images/wallbis1.xpm", &vars->wall->width, &vars->wall->height);
	vars->wallin->img = mlx_xpm_file_to_image(vars->mlx, "./images/trees.xpm", &vars->wall->width, &vars->wall->height);
	vars->BG->img = mlx_xpm_file_to_image(vars->mlx, "./images/snowBG.xpm", &vars->BG->width, &vars->BG->height);
	vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_R.xpm", &vars->player->width, &vars->player->height);
	return (0);
}

void	put_image(t_vars *vars, int x, int y)
{
	
	if (vars->map->tab[vars->map->i][vars->map->j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->BG->img, x, y);
	if ((vars->map->i == 0 || vars->map->i == map_height(vars) - 1 || vars->map->j == 0 || vars->map->j == ft_strlen(vars->map->tab[vars->map->i]) - 1) && vars->map->tab[vars->map->i][vars->map->j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall->img, x, y);
	else if (vars->map->tab[vars->map->i][vars->map->j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wallin->img, x, y);
	if (vars->map->tab[vars->map->i][vars->map->j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect->img, x, y);
	if (vars->map->tab[vars->map->i][vars->map->j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player->img, x, y);
	if (vars->map->tab[vars->map->i][vars->map->j] == 'E')
	{
		vars->mapexit.x = x;
		vars->mapexit.y = y;
		printf("x e= %d y e= %d\n", vars->mapexit.x, vars->mapexit.y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit[0].img, x, y);
	}
}

void	print_map(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars->map->i = 0;
	vars->map->j = 0;
	stock_img(vars);
	stock_img_2(vars);
	while (vars->map->tab[vars->map->i])
	{
		while (vars->map->tab[vars->map->i][vars->map->j])
		{
			put_image(vars, x, y);
			vars->map->j++;
			x = x + 80;
		}
		y = y + 80;
		x = 0;
		vars->map->j = 0;
		vars->map->i++;
	}
}

int	init_santa(t_vars *vars)
{
	vars->santa = malloc(sizeof(t_player));
	if (!vars->santa)
		return (1);
	vars->santa->x = 0;
	vars->santa->y = 0;
	vars->prev_keycode_LR = D_right; /*init vars pas init santa et voir s il faut aussi malloc vars*/
	return (0);
}

int	img_event_collectible(int keycode, t_vars *vars)
{
	// printf("x = %d y = %d\n", vars->mapexit.x, vars->mapexit.y);
	if (vars->map->tab[vars->santa->y / 80][vars->santa->x / 80] == 'C')
	{
		vars->map->tab[vars->santa->y / 80][vars->santa->x / 80] = '0';
		if (keycode == A_left || vars->prev_keycode_LR == A_left)
			vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_present_L.xpm", &vars->player->width, &vars->player->height);
		else
			vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_present_R.xpm", &vars->player->width, &vars->player->height);
		vars->map->c--;
		printf("x = %d\n", vars->map->c);
		if (vars->map->c == 0)
		{
			// vars->map->tab[vars->mapexit.x / 80][vars->mapexit.y / 80] = 'F';
			mlx_put_image_to_window(vars->mlx, vars->win, vars->exit[2].img, vars->mapexit.x, vars->mapexit.y);
		}
		else if (vars->map->c <= vars->map->c2)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->exit[1].img, vars->mapexit.x, vars->mapexit.y);
		return (0);
	}
	return (1);
}

// int	img_event_exit(t_vars *vars)
// {
// 	if (vars->map->tab[vars->santa->y / 80][vars->santa->x / 80] == 'E')
// 	{
// 		if (vars->map->c-- == 0)
// 			vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_present_L.xpm", &vars->player->width, &vars->player->height);
// 		else
// 			vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_present_R.xpm", &vars->player->width, &vars->player->height);
// 		vars->map->c--;
// 		return (0);
// 	}
// 	return (1);
// }

void	img_new_event(int keycode, t_vars *vars)
{
	if (img_event_collectible(keycode, vars) == 1)
	{

		if (keycode == D_right)
			vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_R.xpm", &vars->player->width, &vars->player->height);
		if (keycode == A_left)
			vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_L.xpm", &vars->player->width, &vars->player->height);
		if (keycode == W_top)
		{
			if (vars->prev_keycode_LR == A_left)
				vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_top_L.xpm", &vars->player->width, &vars->player->height);
			else
				vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_T.xpm", &vars->player->width, &vars->player->height);
		}
		else if (keycode == S_bottom)
		{
			if (vars->prev_keycode_LR == D_right) 
				vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_R.xpm", &vars->player->width, &vars->player->height);
			else
				vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./images/santa_L.xpm", &vars->player->width, &vars->player->height);
		}
	}
	// mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player->img, vars->santa->x, vars->santa->y);

}

int	key_hook(int keycode, t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->BG->img, vars->santa->x, vars->santa->y);
	if (keycode == D_right && vars->map->tab[vars->santa->y / 80][(vars->santa->x / 80) + 1] != '1')
	{
		vars->santa->x += 80;
		vars->prev_keycode_LR = D_right;
	}
	if (keycode == A_left  && vars->map->tab[vars->santa->y / 80 ][vars->santa->x/80 - 1] != '1')
	{
		vars->santa->x -= 80;
		vars->prev_keycode_LR = A_left;
	}
	if (keycode == W_top && vars->map->tab[vars->santa->y/80 - 1][vars->santa->x / 80] != '1')
		vars->santa->y -= 80;
	if (keycode == S_bottom && vars->map->tab[vars->santa->y/80 + 1][vars->santa->x / 80] != '1')
		vars->santa->y += 80;
	if (keycode == ESC)
		mlx_destroy_window(vars->mlx, vars->win);  /*voir pour les free*/
	img_new_event(keycode, vars);
	return (0);
}
