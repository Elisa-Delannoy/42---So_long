/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:22:20 by edelanno          #+#    #+#             */
/*   Updated: 2025/01/31 18:22:24 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int     width;
    int     height;
	int		endian;
}				t_img;

typedef	enum	e_key {

	D_right = 100,
	A_left = 97,
	W_top = 119,
	S_bottom = 115,
	ESC = 65307
}				t_key;

typedef struct s_santa {
	int	x;
	int	y;
}				t_santa;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

# endif