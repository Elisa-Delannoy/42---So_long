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

int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	img2;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 900, 700, "Hello world!");
	img.img = mlx_xpm_file_to_image(mlx, "/home/edelanno/42-So_long/images/wall1.xpm", &img.width, &img.height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	img2.img2 = mlx_xpm_file_to_image(mlx, "/home/edelanno/42-So_long/images/wall1.xpm",&img.width, &img.height);
	mlx_put_image_to_window(mlx, mlx_win, img2.img2,80,0);
	mlx_loop(mlx);



}

