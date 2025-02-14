/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:15:14 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/12 15:15:28 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_copy(t_var *var)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = (char **) malloc((var->map->height + 1) * sizeof(char *));
	if (cpy == NULL)
		return (NULL);
	while (var->map->tab[i])
	{
		cpy[i] = ft_strdup(var->map->tab[i]);
		i++;
	}
	return (cpy);
}

int	check_way(t_var *var, size_t x, size_t y, char **cpy)
{
	if (x < 0 || y < 0 || x > var->map->height || y > var->map->width)
		return (1);
	if (cpy[x][y] == '1')
		return (1);
	if (cpy[x][y] == 'E')
		var->map->e--;
	if (cpy[x][y] == 'C')
		var->map->count++;
	cpy[x][y] = '1';
	check_way(var, x + 1, y, cpy);
	check_way(var, x - 1, y, cpy);
	check_way(var, x, y + 1, cpy);
	check_way(var, x, y - 1, cpy);
	return (0);
}

void	check_P_pos(t_var *var)
{
	var->map->i = 0;
	var->map->j = 0;
	while (var->map->tab[var->map->i] && ft_strchr("P", var->map->tab
			[var->map->i][var->map->j]) == NULL)
	{
		if (var->map->tab[var->map->i][var->map->j + 1])
			var->map->j++;
		else
		{
			var->map->j = 0;
			var->map->i++;
		}
	}
	if (ft_strchr("P", var->map->tab[var->map->i][var->map->j]) != NULL)
	{
		var->santa->y = var->map->j;
		var->santa->x = var->map->i;
	}
	check_way(var, var->santa->x, var->santa->y, map_copy(var));
	if (var->map->e != 0 || var->map->count != var->map->c)
		return (ft_putstr_fd("invalid map\n", 2));
	var->santa->x = var->santa->x * 80;
	var->santa->y = var->santa->y * 80;
}

int	parse_map(t_var *var)
{
	if (var->map->i == 0 || var->map->i == map_height(var) - 1 || var->map
			->j == 0 || var->map->j == ft_strlen(var->map->tab[var->map->i]) -1)
	{
		if (ft_strchr("1", var->map->tab[var->map->i][var->map->j]) == NULL)
			return (ft_putstr_fd("must be 1 (wall)\n", 2), 1);
	}
	else
	{
		if (ft_strchr("01CEP", var->map->tab[var->map->i][var->map->j]) == NULL)
			return (ft_putstr_fd("map must be 0, 1, C, E or P\n", 2), 1);
	}
	return (0);
}

int	check_map(t_var *var)
{
	var->map->i = -1;
	var->map->e = 0;
	var->map->p = 0;
	var->map->c = 0;
	while (var->map->tab[++(var->map->i)])
	{
		var->map->j = -1;
		while (var->map->tab[var->map->i][++(var->map->j)])
		{
			if (ft_strchr("E", var->map->tab[var->map->i][var->map->j]) != NULL)
				var->map->e++;
			if (ft_strchr("P", var->map->tab[var->map->i][var->map->j]) != NULL)
				var->map->p++;
			if (ft_strchr("C", var->map->tab[var->map->i][var->map->j]) != NULL)
				var->map->c++;
			if (var->map->e > 1 || var->map->p > 1)
				return (ft_putstr_fd("must have only 1 E and 1 P\n", 2), 1);
			if (parse_map(var) == 1)
				return (1);
		}
	}
	if (var->map->c < 1 || var->map->e < 1 || var->map->p < 1)
		return (ft_putstr_fd("must have 1 E, 1 P and least 1 C\n", 2), 1);
	var->map->c2 = var->map->c / 2;
	return (check_P_pos(var), 0);
}

int	check_rectangular(char **argv, t_var *var)
{
	int		i;
	int		j;
	int		k;

	if (check_name(argv) == 1)
		return (1);
	var->map->tab = stock_map_tab(argv);
	i = 0;
	j = ft_strlen(var->map->tab[i]);
	while (var->map->tab[i])
	{
		k = ft_strlen(var->map->tab[i]);
		if (k != j)
		{
			free_tab(var, var->map->tab);
			return (ft_putstr_fd("map's must be rectangular\n", 2), 1);
		}
		i++;
	}
	if (check_map(var) == 1)
		free_tab(var, var->map->tab);
	return (0);	
}
