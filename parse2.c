/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:15:14 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/19 14:07:21 by edelanno         ###   ########.fr       */
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
	cpy[i] = NULL;
	return (cpy);
}

int	check_way(t_var *var, size_t x, size_t y, char **cpy)
{
	if (x > var->map->height || y > var->map->width)
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

void	check_p_pos(t_var *var)
{
	char	**cpy;

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
		var->santa.x = var->map->j;
		var->santa.y = var->map->i;
	}
	cpy = map_copy(var);
	check_way(var, var->santa.y, var->santa.x, cpy);
	free_tab(cpy);
}

int	parse_map(t_var *var)
{
	if (var->map->i == 0 || var->map->i == map_height(var) - 1 || var->map
		->j == 0 || var->map->j == ft_strlen(var->map->tab[var->map->i]) - 1)
	{
		if (ft_strchr("1", var->map->tab[var->map->i][var->map->j]) == NULL)
			return (ft_putstr_fd("must be 1 (wall)\n", 2), 1);
	}
	else
	{
		if (ft_strchr("01CEPM", var->map->tab[var->map->i][var->map->j]) == NULL)
			return (ft_putstr_fd("map must be 0, 1, C, E, P or M\n", 2), 1);
	}
	return (0);
}

int	check_map(t_var *var)
{
	while (var->map->tab[(var->map->i)])
	{
		var->map->j = 0;
		while (var->map->tab[var->map->i][(var->map->j)])
		{
			if (ft_strchr("E", var->map->tab[var->map->i][var->map->j]) != NULL)
				var->map->e++;
			if (ft_strchr("P", var->map->tab[var->map->i][var->map->j]) != NULL)
				var->map->p++;
			if (ft_strchr("C", var->map->tab[var->map->i][var->map->j]) != NULL)
				var->map->c++;
			if (ft_strchr("M", var->map->tab[var->map->i][var->map->j]) != NULL)
				var->map->m++;
			if (var->map->e > 1 || var->map->p > 1)
				return (ft_putstr_fd("must have only 1 E and 1 P\n", 2), 1);
			if (parse_map(var) == 1)
				return (1);
			var->map->j++;
		}
		var->map->i++;
	}
	if (var->map->c < 1 || var->map->e < 1 || var->map->p < 1)
		return (ft_putstr_fd("must have 1 E, 1 P and least 1 C\n", 2), 1);
	var->map->c2 = var->map->c / 2;
	check_p_pos(var);
	if (var->map->e != 0 || var->map->count != var->map->c)
		return (ft_putstr_fd("invalid map\n", 2), 1);
	return (0);
}
