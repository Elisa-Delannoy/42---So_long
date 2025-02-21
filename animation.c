/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:42:01 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/21 13:45:21 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	santa_anim(t_var *var, int x, int y)
{
	
	if (var->stock_keycode == Q_kill && var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'W' && var->i_wait_fight != 0 && var->i_wait_fight < 3)
	{
		kill_ennemy(var, 0);
	}
	else if (var->map->tab[y / 80][x / 80] == 'T')
	{
		// printf("keycode sanat %d\n", var->stock_keycode);
		if (var->stock_keycode == A_left || (var->stock_keycode != A_left
				&& var->prev_keycode_lr == A_left))
			mlx_put_image_to_window(var->mlx, var->win,
				var->pp_a[1][var->i].img, x, y);
		else
			mlx_put_image_to_window(var->mlx, var->win,	var->pp_a[0][var->i].img, x, y);
	}
	else if (var->map->move == 0 || var->stock_keycode == D_right
		|| var->stock_keycode == A_left || var->stock_keycode == S_bottom || var->stock_keycode == Q_kill)
	{
		// printf("santa");
		if (var->map->move == 0 || var->stock_keycode == D_right || (var
				->stock_keycode == S_bottom && var->prev_keycode_lr == D_right) || (var
				->stock_keycode == Q_kill && var->prev_keycode_lr == D_right))
			mlx_put_image_to_window(var->mlx, var->win,
				var->p_a[0][var->i].img, x, y);
		else if (var->stock_keycode == A_left || (var->stock_keycode == S_bottom
				&& var->prev_keycode_lr == A_left) || (var->stock_keycode == Q_kill
				&& var->prev_keycode_lr == A_left))
			mlx_put_image_to_window(var->mlx, var->win,
				var->p_a[1][var->i].img, x, y);
		// var->i_wait_fight = 0;
	}
	if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'D')
	{
		if (var->stock_keycode == A_left || var->prev_keycode_lr == A_left)
				mlx_put_image_to_window(var->mlx, var->win,	var->dead[1].img,
				var->santa.x, var->santa.y);
		else
			mlx_put_image_to_window(var->mlx, var->win,	var->dead[0].img, 
			var->santa.x, var->santa.y);
	
	}
	else if (var->stock_keycode == W_top && var->prev_keycode_lr == D_right)
		mlx_put_image_to_window(var->mlx, var->win,	var->p[0].img, x, y);
	else if (var->stock_keycode == W_top && var->prev_keycode_lr == A_left)
		mlx_put_image_to_window(var->mlx, var->win,	var->p[1].img, x, y);

}

void	dead(t_var *var, size_t i)
{
	if (var->e[i].y == (var->santa.x / 80) && var->e[i].x == (var->santa.y / 80)
		&& var->map->tab[var->pos_en[i].y][var->pos_en[i].x] == 'M')
	{
		if (var->stock_keycode == A_left || var->prev_keycode_lr == A_left)
				mlx_put_image_to_window(var->mlx, var->win,	var->dead[1].img,
				var->santa.x, var->santa.y);
		else
			mlx_put_image_to_window(var->mlx, var->win,	var->dead[0].img, 
			var->santa.x, var->santa.y);
		if (var->map->tab[var->santa.y / 80][var->santa.x / 80] != 'D')
			var->i_wait_dead = 1;
		var->map->tab[var->pos_en[i].y][var->pos_en[i].x] = 'D';
		var->map->tab[var->santa.y / 80][var->santa.x / 80] = 'D';
		if (var->i_wait_dead == 1)
		{
			
			exit_game(var);
		}
	}
}

void	move_ennemy(t_var *var, size_t i)
{
	if (var->map->tab[var->e[i].x + 1][var->e[i].y ] == '0' )
		var->e[i].x =var->e[i].x + 1;
	else if (var->map->tab[var->e[i].x][var->e[i].y + 1] == '0')
		var->e[i].y = var->e[i].y + 1;
	else if (var->map->tab[var->e[i].x ][var->e[i].y - 1] == '0')
		var->e[i].y = var->e[i].y - 1;
	else if (var->map->tab[var->e[i].x - 1][var->e[i].y ] == '0')
		var->e[i].x =var->e[i].x - 1;
	
}


void	ennemies_anim(t_var *var)
{
	int i = 0;
	
	while (var->e[i].x != 0 && (var->map->tab[var->pos_en[i].y]
		[var->pos_en[i].x] == 'M'|| var->map->tab[var->pos_en[i].y]
		[var->pos_en[i].x] == 'K'))
	{
		
	
		if (var->i_loop == 0)
		{
			// printf("pos ennemi %d\n", var->pos_en[i].y);
			// printf("pos ennemi %d\n", var->pos_en[i].x);
			// printf("pos e %d\n", var->e[i].x);
			// printf("pos e %d\n", var->e[i].y);
			
			// var->map->tab[var->e[i].x][var->e[i].y ] = '2';
			if (var->e[i].y != var->santa.x / 80 || var->e[i].x 
				!= var->santa.y / 80)
				mlx_put_image_to_window(var->mlx, var->win,	var->bg.img,
				var->e[i].y * 80, var->e[i].x * 80);
			// if (var->map->tab[var->e[i].x][var->e[i].y] == '0')
			// 	var->map->tab[var->e[i].x][var->e[i].y] = '0';			
			if (var->map->tab[var->e[i].x][var->e[i].y] == '2')
				var->map->tab[var->e[i].x][var->e[i].y] = '0';	
			move_ennemy(var, i);
			if (var->map->tab[var->e[i].x][var->e[i].y] != 'M'
				&& var->map->tab[var->e[i].x][var->e[i].y] != 'K')
				var->map->tab[var->e[i].x][var->e[i].y] = '2';
			if (var->map->tab[var->pos_en[i].y][var->pos_en[i].x] == 'M')
				mlx_put_image_to_window(var->mlx, var->win,	var->ennemy.img,
					var->e[i].y * 80, var->e[i].x * 80);		
			else if (var->map->tab[var->pos_en[i].y][var->pos_en[i].x] == 'K'
				&& (var->e[i].y != var->santa.x / 80 || var->e[i].x 
				!= var->santa.y / 80))
				mlx_put_image_to_window(var->mlx, var->win,	var->bg.img, 
				var->e[i].y * 80, var->e[i].x * 80);
			// wait_after_kill(var, i);
		}
		dead(var, i);
		i++;
	}
}

// void	wait_after_kill(t_var *var, int i)
// {
// 	if (var->i_wait_fight < 2)
// 		kill_ennemy(var, i);
// 	// if (var->i_wait_fight)
// 		// 	i++;
// 		// 	if (i == 100000)
// 		// 		var->stock_keycode = D_right;
// 		// }
// }


void	kill_ennemy(t_var *var, int i)
{
	int	j;

	// printf("dans kill %d\n", var->i_wait_fight);
	// printf("%d\n", var->stock_keycode);
	while (var->e[i].x != 0 && var->stock_keycode == Q_kill)
	{
		j = - 1;
		if (var->e[i].y - 1 == var->santa.x / 80 && var->e[i].x == var->santa.y / 80)
			j = 0;
		else if (var->e[i].y + 1 == var->santa.x / 80 && var->e[i].x == var->santa.y / 80)
			j = 1;
		else if (var->e[i].y == var->santa.x / 80 && var->e[i].x + 1 == var->santa.y / 80)
			j = 2;
		else if (var->e[i].y == var->santa.x / 80 && var->e[i].x - 1 == var->santa.y / 80)
			j = 3;
		if (j != - 1)
		{
			printf("dans kill dans while %d\n", var->i_wait_fight);
			if (var->i_wait_fight == 0)
			{
				printf("%d\n", var->i_wait_fight);
				var->i_wait_fight = 1;
				var->map->tab[var->pos_en[i].y][var->pos_en[i].x] = 'K';
				var->map->tab[var->santa.y / 80][var->santa.x / 80] = 'W';
				mlx_put_image_to_window(var->mlx, var->win,	var->santa_fight[j].img, var->santa.x, var->santa.y);
				mlx_put_image_to_window(var->mlx, var->win,	var->bg.img, var->e[i].y * 80, var->e[i].x * 80);
			}
			if (var->i_wait_fight ==  2)
				var->map->tab[var->santa.y / 80][var->santa.x / 80] = '0';
			{

			if (var->i_wait_fight == 2)
					var->map->tab[var->santa.y / 80][var->santa.x / 80] = '0';
			}
		}
		i++;
	}
}
