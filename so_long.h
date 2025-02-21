/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:22:20 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/21 16:03:54 by edelanno         ###   ########.fr       */
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

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stddef.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef enum e_key
{
	D_right = 100,
	A_left = 97,
	W_top = 119,
	S_bottom = 115,
	Q_kill = 113,
	ESC = 65307
}				t_key;

typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct s_map
{
	size_t	i;
	size_t	j;
	int		e;
	int		p;
	int		c;
	int		c2;
	int		m;
	char	**tab;
	size_t	height;
	size_t	width;
	int		count;
	int		move;
	char	*printmove;
}				t_map;

typedef struct s_var
{
	int			prev_keycode_lr;
	int			stock_keycode;
	int			previous_keycode;
	void		*mlx;
	void		*win;
	int			i;
	int			i_loop;
	int			i_wait_dead;
	int			i_wait_fight;
	int			i_count_wait;
	t_map		*map;
	t_player	santa;
	t_img		bg;
	t_img		p[3];
	t_img		p_a[2][4];
	t_img		pp_a[2][2];
	t_img		collect;
	t_img		dead[2];
	t_img		exit[3];
	t_img		wall[2];
	t_img		ennemy;
	t_img		santa_fight[4];
	t_player	mapexit;
	t_player	*pos_en;
	t_player	*e;
}				t_var;

t_list	*open_read(char **argv);
char	**stock_map_tab(char **argv);
int		check_rectangular(char **argv, t_var *var);
int		check_name(char **argv);
int		check_map(t_var *var);
size_t	map_height(t_var *var);
int		key_hook(int keycode, t_var *var);
int		init_santa(t_var *var);
int		print_map(t_var *var);
int		exit_game(t_var *var);
void	free_tab(char **tab);
void	free_all(t_var *var);
int		print_map(t_var *var);
int		img_event_exit(t_var *var);
int		init_santa(t_var *var);
int		init_map(t_var *var);
void	init_var(t_var *var);
void	free_img(t_var *var);
void	free_all(t_var *var);
void	img_new_event(int keycode, t_var *var, int x, int y);
void	santa_anim(t_var *var, int x, int y);
void	ennemies_anim(t_var *var, int i);
void	kill_ennemy(t_var *var, int i);
void	dead(t_var *var, size_t i);
void	init_printmap(t_var *var);
int		stock_img(t_var *var);
char	**map_copy(t_var *var);

char	*get_next_line(int fd);
size_t	ft_strlen_line(const char *s);
char	*ft_strchr_line(const char *s, int c);
char	*ft_strjoin_line(char const *s1, char const *s2);
char	*ft_strdup_line(const char *s);
char	*ft_temp(char **newbuffer, char *buffer, int i);
char	*ft_read(int fd, char *buffer, char **newbuffer);
void	*ft_calloc_line(size_t nmemb, size_t size);
void	ft_bzero_line(void *s, size_t n);
#endif