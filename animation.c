/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:42:01 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/18 17:35:57 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	santa_anim(t_var *var, int x, int y)
{
	if (var->map->tab[y / 80][x / 80] == 'T')
	{
		if (var->stock_keycode == A_left || (var->stock_keycode != A_left && var->prev_keycode_lr == A_left))
			mlx_put_image_to_window(var->mlx, var->win, var->pp_a[1][var->i].img,
				x, y);
		else
			mlx_put_image_to_window(var->mlx, var->win, var->pp_a[0][var->i].img,
				x, y);
	}
	else if (var->map->move == 0 || var->stock_keycode == D_right || var->stock_keycode == A_left || var->stock_keycode == S_bottom)
	{
		
		if (var->map->move == 0 || var->stock_keycode == D_right || (var->stock_keycode == S_bottom && var->prev_keycode_lr == D_right))
			mlx_put_image_to_window(var->mlx, var->win, var->p_a[0][var->i].img, x, y);
		else if (var->stock_keycode == A_left || (var->stock_keycode == S_bottom && var->prev_keycode_lr == A_left))
			mlx_put_image_to_window(var->mlx, var->win, var->p_a[1][var->i].img, x, y);
	}
}

