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

char	**map_copy(t_map *map)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = (char **) malloc((map->height + 1) * sizeof(char *));
	if (cpy == NULL)
		return (NULL);
	while (map->tab[i])
	{
		cpy[i] = ft_strdup(map->tab[i]);
		i++;
	}
	return (cpy);
}

int	check_way(t_map *map, size_t x, size_t y, char **cpy)
{
	// if (x > map_width(tab) || y > ft_strlen(tab[0]))
	// 	return ;
	if ((ft_strchr("1", cpy[x][y]) != NULL))
		return (1);
	if ((ft_strchr("E", cpy[x][y]) != NULL))
		map->e--;
	if ((ft_strchr("C", cpy[x][y]) != NULL))
		map->c--;
	cpy[x][y] = '1';
	check_way(map, x + 1, y, cpy);
	check_way(map, x - 1, y, cpy);
	check_way(map, x, y + 1, cpy);
	check_way(map, x, y - 1, cpy);
	if (map->e != 0 && map->c != 0)
		return (2);
	return (0);
}

void	check_P_pos(t_map *map, t_vars *vars)
{
	// size_t	x;
	// size_t	y;

	map->i = 0;
	map->j = 0;
	while (map->tab[map->i] && ft_strchr("P", map->tab[map->i][map->j]) == NULL)
	{
		if (map->tab[map->i][map->j + 1])
			map->j++;
		else
		{
			map->j = 0;
			map->i++;
		}
	}
	if (ft_strchr("P", map->tab[map->i][map->j]) != NULL)
	{
		vars->santa->x = map->i;
		vars->santa->y = map->j;
	}
	if (check_way(map, vars->santa->x, vars->santa->y, map_copy(map)) == 2)
		return (perror("invalid way"));
}

int	parse_map(t_map *map)
{
	if (map->i == 0 || map->i == map_height(map) || map->j == 0 || map->j == ft_strlen(map->tab[map->i]) - 1)
	{
		if (ft_strchr("1", map->tab[map->i][map->j]) == NULL)
			return (perror("must be wall"), 1);
	}
	else
	{
		if (ft_strchr("01CEP", map->tab[map->i][map->j]) == NULL)
			return (perror("map must be 0, 1, C, E or P"), 1);
	}
	return (0);
}

void	check_map(t_map *map, t_vars *vars)
{
	map->i = -1;
	map->e = 0;
	map->p = 0;
	map->c = 0;
	while (map->tab[++(map->i)])
	{
		map->j = -1;
		while (map->tab[map->i][++(map->j)])
		{
			if (ft_strchr("E", map->tab[map->i][map->j]) != NULL)
				map->e++;
			if (ft_strchr("P", map->tab[map->i][map->j]) != NULL)
				map->p++;
			if (ft_strchr("C", map->tab[map->i][map->j]) != NULL)
				map->c++;
			if (map->e > 1 || map->p > 1)
				return (perror("must have only 1 exit E and 1 player P"), exit (1));
			if (parse_map(map) == 1)
				return ;
		}
	}
	if (map->c < 1 || map->e < 1 || map->p < 1)
		return (perror("must have 1 exit, 1 player and least 1 collectible C"), exit (1));
	check_P_pos(map, vars);
}

char	**check_rectangular(char **argv, t_map *map, t_vars *vars)
{
	int		i;
	int		j;
	int		k;

	map->tab = stock_map_tab(argv);
	i = 0;
	j = ft_strlen(map->tab[i]);
	while (map->tab[i])
	{
		k = ft_strlen(map->tab[i]);
		if (k != j)
			return (perror("map's must be rectangular"), NULL);
		i++;
	}
	check_map(map, vars);
	return (map->tab);	
}
