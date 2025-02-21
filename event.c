/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:27 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/21 15:14:35 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_var *var)
{
	var->map->move++;
	var->map->printmove = ft_itoa(var->map->move);
	mlx_put_image_to_window(var->mlx, var->win, var->wall[0].img, 240, -10);
	mlx_string_put(var->mlx, var->win, 160, 30, 0xFFFFFF, "movement :");
	mlx_string_put(var->mlx, var->win, 240, 30, 0xFFFFFF, var->map->printmove);
	free(var->map->printmove);
}

void	key(int keycode, t_var *var)
{
	if (keycode == D_right)
		var->santa.x += 80;
	if (keycode == A_left)
		var->santa.x -= 80;
	if (keycode == W_top)
		var->santa.y -= 80;
	if (keycode == S_bottom)
		var->santa.y += 80;
}

void	update_map_or_value_or_quit(t_var *var, int keycode)
{
	if (keycode != Q_kill)
		var->previous_keycode = var->stock_keycode;
	var->i_wait_fight = 0;
	var->stock_keycode = keycode;
	if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'T')
		var->map->tab[var->santa.y / 80][var->santa.x / 80] = '0';
	if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'P')
		var->map->tab[var->santa.y / 80][var->santa.x / 80] = '0';
	if (keycode == ESC)
		exit_game(var);
}

int	key_hook(int keycode, t_var *var)
{
	t_player	p;

	p.x = var->santa.x;
	p.y = var->santa.y;
	update_map_or_value_or_quit(var, keycode);
	if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'D')
		return (1);
	if (keycode == A_left || keycode == W_top || keycode == S_bottom
		|| keycode == D_right)
	{
		img_event_exit(var);
		key(keycode, var);
		if (var->map->tab[var->santa.y / 80][(var->santa.x / 80)] == '1')
		{
			var->santa.x = p.x;
			var->santa.y = p.y;
		}
		else
			print_move(var);
	}
	if (keycode == A_left || keycode == D_right)
		var->prev_keycode_lr = keycode;
	img_new_event(keycode, var, var->santa.x, var->santa.y);
	return (0);
}
