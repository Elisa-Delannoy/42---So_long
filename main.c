/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:30:05 by edelanno          #+#    #+#             */
/*   Updated: 2025/01/30 11:30:06 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "so_long.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void	init_santa(t_santa *santa)
{
	santa->x = 0;
	santa->y = 0;
}

int	key_hook(int keycode, t_santa *santa)
{

	if (keycode == D_right)
		santa->x = santa->x + 80;
	if (keycode == A_left)
		santa->x = santa->x - 80;
	if (keycode == W_top)
		santa->y = santa->y + 80;
	if (keycode == S_bottom)
		santa->y = santa->y - 80;
	printf("x = %d\n", santa->x);
	printf("y = %d\n", santa->y);
	// mlx_clear_window(vars.mlx, vars.win);
	// mlx_put_image_to_window(vars->mlx, vars->win, img.img, santa->x, santa->y);
	return (0);
}

int	main()
{
	t_img	img;
	// t_data	img2;
	t_vars	vars;
	t_santa	*santa;

	santa = NULL;
	santa = malloc(sizeof(t_santa));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	init_santa(santa);
	printf("x = %d\n", santa->x);
	printf("y = %d\n", santa->y);
	img.img = mlx_xpm_file_to_image(vars.mlx, "./images/santa_R.xpm", &img.width, &img.height);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, santa->x, santa->y);
	// img2.img2 = mlx_xpm_file_to_image(vars.mlx, "./images/wall1.xpm",&img.width, &img.height);
	// mlx_put_image_to_window(vars.mlx, vars.win, img2.img2,100,100);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);



}

