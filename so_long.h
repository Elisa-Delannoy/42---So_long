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
#include <X11/X.h>
#include <X11/keysym.h>
#include <stddef.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


typedef struct	s_img {

	void	*img;
	int		width;
	int		height;
}				t_img;

typedef	enum	e_key {

	D_right = 100,
	A_left = 97,
	W_top = 119,
	S_bottom = 115,
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
	int		c2;
	char	**tab;
	size_t	height;
	size_t	width;
	int		count;
}				t_map;

typedef struct	s_var {
	int			prev_keycode_LR;
	void		*mlx;
	void		*win;
	t_map		*map;
	t_img		*img;
	t_player	*santa;
	t_img		BG;
	t_img		p[6];
	t_img		collect;
	t_img		exit[3];
	t_img		wall[2];
	t_player	mapexit;
}				t_var;


t_list	*open_read(char **argv);
char	**stock_map_tab(char **argv);
char	**check_rectangular(char **argv, t_var *var);
void	check_map(t_var *var);
size_t	map_height(t_var *var);
int		key_hook(int keycode, t_var *var);
int		init_santa(t_var *var);
int		print_map(t_var *var);
int		exit_game(t_var *var);

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