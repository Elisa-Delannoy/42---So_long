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
	var->BG.img = mlx_xpm_file_to_image(var->mlx,
			"./images/snowBG.xpm", &var->BG.width, &var->BG.height);
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
	return (0);
}

void	put_image(t_var *var, int x, int y)
{
	if (var->map->tab[var->map->i][var->map->j] == '0')
		mlx_put_image_to_window(var->mlx, var->win, var->BG.img, x, y);
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
	stock_img_2(var);
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
	return (0);
}

int	init_santa(t_var *var)
{
	var->santa = malloc(sizeof(t_player));
	if (!var->santa)
		return (1);
	var->santa->x = 0;
	var->santa->y = 0;
	var->prev_keycode_LR = D_right;
	return (0);
}

int	img_event_exit(t_var *var)
{
	if (var->map->tab[var->santa->y / 80][var->santa->x / 80] == 'E'
		&& var->map->c == 0)
		mlx_destroy_window(var->mlx, var->win);
	return (1);
}

int	img_event_collectible(int keycode, t_var *var)
{
	if (var->map->tab[var->santa->y / 80][var->santa->x / 80] == 'C')
	{
		var->map->tab[var->santa->y / 80][var->santa->x / 80] = '0';
		if (keycode == A_left || var->prev_keycode_LR == A_left)
			mlx_put_image_to_window(var->mlx, var->win, var->p[5].img,
				var->santa->x, var->santa->y);
		else
			mlx_put_image_to_window(var->mlx, var->win, var->p[4].img,
				var->santa->x, var->santa->y);
		var->map->c--;
		if (var->map->c == 0)
			mlx_put_image_to_window(var->mlx, var->win, var->exit[2].img,
				var->mapexit.x, var->mapexit.y);
		else if (var->map->c <= var->map->c2)
			mlx_put_image_to_window(var->mlx, var->win, var->exit[1].img,
				var->mapexit.x, var->mapexit.y);
		return (0);
	}
	img_event_exit(var);
	return (1);
}

void	img_new_event(int keycode, t_var *var, int x, int y)
{
	if (img_event_collectible(keycode, var) == 1)
	{
		if (keycode == D_right)
			mlx_put_image_to_window(var->mlx, var->win, var->p[0].img, x, y);
		if (keycode == A_left)
			mlx_put_image_to_window(var->mlx, var->win, var->p[1].img, x, y);
		if (keycode == W_top)
		{
			if (var->prev_keycode_LR == A_left)
				mlx_put_image_to_window(var->mlx, var->win, var->p[3].img,
				x, y);
			else
				mlx_put_image_to_window(var->mlx, var->win, var->p[2].img,
				x, y);
		}
		else if (keycode == S_bottom)
		{
			if (var->prev_keycode_LR == D_right)
				mlx_put_image_to_window(var->mlx, var->win, var->p[0].img,
				x, y);
			else
				mlx_put_image_to_window(var->mlx, var->win, var->p[1].img,
				x, y);
		}
	}
}

int	exit_game(t_var *var)
{
	mlx_destroy_window(var->mlx, var->win);/*voir pour les free*/
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	exit (0);
}

int	key_hook(int keycode, t_var *var)
{
	t_player	p;

	p.x = var->santa->x;
	p.y = var->santa->y;
	if ((keycode == A_left || keycode == W_top || keycode == S_bottom
		|| keycode == D_right))
	{
		mlx_put_image_to_window(var->mlx, var->win, var->BG.img, var->santa->x, var->santa->y);
		
		if (keycode == D_right)
			var->santa->x += 80;
		if (keycode == A_left)
			var->santa->x -= 80;
		if (keycode == W_top)
			var->santa->y -= 80;
		if (keycode == S_bottom) 
			var->santa->y += 80;
		if (keycode == ESC)
			exit_game(var);
		if (var->map->tab[var->santa->y / 80][(var->santa->x / 80)] == '1')
		{
			var->santa->x = p.x;
			var->santa->y = p.y;
		}
		else 
			var->map->count++;
	}
	if (keycode == A_left || keycode == D_right)
		var->prev_keycode_LR = keycode;
	mlx_put_image_to_window(var->mlx, var->win, var->wall[0].img, 80, 0);
	mlx_string_put(var->mlx, var->win, 10, 10, 0xFFFFFF, "movement :");
	mlx_string_put(var->mlx, var->win, 80, 10, 0xFFFFFF, ft_itoa(var->map->count));
	img_new_event(keycode, var, var->santa->x, var->santa->y);
	return (0);
}
