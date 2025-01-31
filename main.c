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
#include <stddef.h> 

typedef struct	s_data {
	void	*img;
	void	*img2;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int     width;
    int     height;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	main()
{

	t_vars	vars;
	t_data	img;
	t_data	img2;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 900, 700, "Hello world!");
	img.img = mlx_xpm_file_to_image(vars.mlx, "/home/edelanno/42-So_long/images/santa_R.xpm", &img.width, &img.height);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	img2.img2 = mlx_xpm_file_to_image(vars.mlx, "/home/edelanno/42-So_long/images/wall1.xpm",&img.width, &img.height);
	mlx_put_image_to_window(vars.mlx, vars.win, img2.img2,80,0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);



}

