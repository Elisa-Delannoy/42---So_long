/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:30:05 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/21 13:43:27 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	wait_after_kill(t_var *var)
// {
	
// }

int loop_hook(t_var *var)
{
	var->i_loop = (var->i_loop + 1) % 10000;
	// printf("i debut loop%d\n", var->i);
	if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'W' && var->i_loop == 0)
	{
		// printf("i kill loop%d\n", var->i_wait_fight);
		kill_ennemy(var, 0);
		// if (var->i_wait_fight == 0)
		// 	var->i--;
		var->i_wait_fight++;
	}
	else if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'D' && var->i_loop == 0)
	{
		// printf("i deqd loop%d\n", var->i_wait_dead);
		exit_game(var);
		// if (var->i_wait_dead == 0)
		// 	var->i--;
		var->i_wait_dead++;
	}
	else if (var->map->tab[var->santa.y / 80][var->santa.x / 80] != 'D' && var->map->tab[var->santa.y / 80][var->santa.x / 80] != 'W')
	{
		// printf("sanat %c\n", var->map->tab[var->santa.y / 80][var->santa.x / 80]);
		// printf("i var i%d\n", var->i );
		if (var->i_loop == 0)
			var->i++;
		if (var->i > 3)
			var->i = 0;
		if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'T')
		// if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'T' || var->stock_keycode == Q_kill || var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'D')
		{
			// printf("i var i%d\n", var->i );
			if (var->i > 1)
				var->i = 0;
			// else if (var->i != 0)
			// 	var->i = 0;
		}
		santa_anim(var, var->santa.x, var->santa.y);
		ennemies_anim(var);
		kill_ennemy(var, 0);
		// printf("%d\n", var->i_loop);
	}
	return (0);
}



// void	to_loop

// int loop_hook(t_var *var)
// {
// 	var->i_loop = (var->i_loop + 1) % 10000;
// 	if (var->map->tab[var->santa.y / 80][var->santa.x / 80] == 'T')
// 	{
// 		if (var->i_loop < 2500 || (var->i_loop >= 5000 && var->i_loop < 7500))
// 			var->i = 0;
// 		else if ((var->i_loop >= 2500 && var->i_loop < 5000) || var->i_loop >= 7500)
// 			var->i = 1;
// 	}
// 	else if (var->i_loop >= 2500 && var->i_loop < 5000)
// 		var->i = 1;
// 	else if (var->i_loop >= 5000 && var->i_loop < 7500)
// 		var->i = 2;
// 	else if (var->i_loop >= 7500)
// 		var->i = 3;
// 	else if(var->i_loop == 0)
// 		var->i = 0;
// 	// else if (var->map->tab[var->pos_ennemy.y / 80][var->pos_ennemy.x / 80] == 'M' && var->i_loop == 0)
// 	// 	var->i_M++;
	
// 	santa_anim(var, var->santa.x, var->santa.y);
// 	ennemies_anim(var);
// 	kill_ennemy(var, 0);
// 	return (0);
// }



// void	printmaptocheck(t_var *var)
// {
// 	int i = 0;
// 	int j = 0;
	
// 	while (var->map->tab[i])
// 	{
// 		while (var->map->tab[i][j])
// 		{
// 			printf("%c",var->map->tab[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		j = 0;
// 		i++;
// 	}

// }

void	checkprntmap(t_var *var)
{
	int i = 0;
	int j = 0;
	while (var->map->tab[i])
	{
		while (var->map->tab[i][j])
		{
			printf("%c", var->map->tab[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	printf("\n");
	printf("next");
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_var		var;

	if (argc != 2)
		return (1);
	var.mlx = mlx_init();
	var.win = NULL;
	init_var(&var);
	init_santa(&var);
	if (init_map(&var) == 1)
	{
		free_all(&var);
		return (1);
	}
	if (check_rectangular(argv, &var) == 1)
	{
		free_all(&var);
		return (1);
	}
	var.santa.x = var.santa.x * 80;
	var.santa.y = var.santa.y * 80;
	var.win = mlx_new_window(var.mlx, 80 * (var.map->width + 1),
			80 * (var.map->height), "Santa!");
	mlx_expose_hook(var.win, print_map, &var);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_hook(var.win, DestroyNotify, KeyReleaseMask, exit_game, &var);
	mlx_loop_hook(var.mlx, loop_hook, &var);
	mlx_loop(var.mlx);
	return (0);
}
