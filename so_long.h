/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:22:20 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/11 20:50:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# if BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE 
#  define BUFFER_SIZE 1000000
# endif

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <stddef.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

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
	A_left = 115,
	W_top = 97,
	S_bottom = 119,
	ESC = 65307
}				t_key;

typedef struct s_player {
	int	x;
	int	y;
}				t_player;



typedef struct s_map {
	size_t	i;
	size_t	j;
	int		e;
	int		p;
	int		c;
}				t_map;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_img		*img;
	t_player	*santa;
}				t_vars;


t_list	*open_read(char **argv);
char	**stock_map_tab(char **argv);
char	**check_rectangular(char **argv, t_map *map);
void	check_map(t_map *map, char **tab);

/*voir comment ajouter le dossier gnl dans Makefile ou voir pour modifier les fonctions de la libft*/
char	*get_next_line(int fd);
size_t	ft_strlen_line(const char *s);
char	*ft_strchr_line(const char *s, int c);
char	*ft_strjoin_line(char const *s1, char const *s2);
char	*ft_strdup_line(const char *s);
char	*ft_temp(char **newbuffer, char *buffer, int i);
char	*ft_read(int fd, char *buffer, char **newbuffer);
void	*ft_calloc_line(size_t nmemb, size_t size);
void	ft_bzero_line(void *s, size_t n);
# endif