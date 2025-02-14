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
	int	count;
	// if (x > map_width(tab) || y > ft_strlen(tab[0]))
	// 	return ;
	count = 0;
	if ((ft_strchr("1", cpy[x][y]) != NULL))
		return (1);
	if ((ft_strchr("E", cpy[x][y]) != NULL))
		var->map->e--;
	if ((ft_strchr("C", cpy[x][y]) != NULL))
		count++;
	cpy[x][y] = '1';
	check_way(var, x + 1, y, cpy);
	check_way(var, x - 1, y, cpy);
	check_way(var, x, y + 1, cpy);
	check_way(var, x, y - 1, cpy);
	if (var->map->e != 0 && count != var->map->c)
		return (2);
	return (0);
}

void	check_P_pos(t_var *var)
{
	var->map->i = 0;
	var->map->j = 0;
	while (var->map->tab[var->map->i] && ft_strchr("P", var->map->tab[var->map->i][var->map->j]) == NULL)
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
		var->santa->x = var->map->j;
		var->santa->y = var->map->i;
	}
	if (check_way(var, var->santa->x, var->santa->y, map_copy(var)) == 2)
		return (perror("invalid way"));
	var->santa->x = var->santa->x * 80;
	var->santa->y = var->santa->y * 80;
}

int	parse_map(t_var *var)
{
	if (var->map->i == 0 || var->map->i == map_height(var) - 1 || var->map->j == 0 || var->map->j == ft_strlen(var->map->tab[var->map->i]) - 1)
	{
		if (ft_strchr("1", var->map->tab[var->map->i][var->map->j]) == NULL)
			return (perror("must be wall"), 1);
	}
	else
	{
		if (ft_strchr("01CEP", var->map->tab[var->map->i][var->map->j]) == NULL)
			return (perror("map must be 0, 1, C, E or P"), 1);
	}
	return (0);
}

void	check_map(t_var *var)
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
				return (perror("must have only 1 exit E and 1 player P"), exit (1));
			if (parse_map(var) == 1)
				return ;
		}
	}
	if (var->map->c < 1 || var->map->e < 1 || var->map->p < 1)
		return (perror("must have 1 exit, 1 player and least 1 collectible C"), exit (1));
	var->map->c2 = var->map->c / 2;
	check_P_pos(var);
}

char	**check_rectangular(char **argv, t_var *var)
{
	int		i;
	int		j;
	int		k;

	var->map->tab = stock_map_tab(argv);
	i = 0;
	j = ft_strlen(var->map->tab[i]);
	while (var->map->tab[i])
	{
		k = ft_strlen(var->map->tab[i]);
		if (k != j)
			return (perror("map's must be rectangular"), NULL);
		i++;
	}
	check_map(var);
	return (var->map->tab);	
}
