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
	int		prev_keycode_LR;
	int		prev_keycode;
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
	A_top = 97,
	W_bottom = 119,
	S_left = 115,
	ESC = 65307
}				t_key;

typedef struct s_player {
	int	x;
	int	y;
}				t_player;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_img		*img;
	t_player	*santa;
}				t_vars;

# endif