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

char	**map_copy(t_vars *vars)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = (char **) malloc((vars->map->height + 1) * sizeof(char *));
	if (cpy == NULL)
		return (NULL);
	while (vars->map->tab[i])
	{
		cpy[i] = ft_strdup(vars->map->tab[i]);
		i++;
	}
	return (cpy);
}

int	check_way(t_vars *vars, size_t x, size_t y, char **cpy)
{
	int	count;
	// if (x > map_width(tab) || y > ft_strlen(tab[0]))
	// 	return ;
	count = 0;
	if ((ft_strchr("1", cpy[x][y]) != NULL))
		return (1);
	if ((ft_strchr("E", cpy[x][y]) != NULL))
		vars->map->e--;
	if ((ft_strchr("C", cpy[x][y]) != NULL))
		// vars->map->c--;
		count++;
	cpy[x][y] = '1';
	check_way(vars, x + 1, y, cpy);
	check_way(vars, x - 1, y, cpy);
	check_way(vars, x, y + 1, cpy);
	check_way(vars, x, y - 1, cpy);
	if (vars->map->e != 0 && count != vars->map->c)
		return (2);
	return (0);
}

void	check_P_pos(t_vars *vars)
{
	vars->map->i = 0;
	vars->map->j = 0;
	while (vars->map->tab[vars->map->i] && ft_strchr("P", vars->map->tab[vars->map->i][vars->map->j]) == NULL)
	{
		if (vars->map->tab[vars->map->i][vars->map->j + 1])
			vars->map->j++;
		else
		{
			vars->map->j = 0;
			vars->map->i++;
		}
	}
	if (ft_strchr("P", vars->map->tab[vars->map->i][vars->map->j]) != NULL)
	{
		vars->santa->x = vars->map->j;
		vars->santa->y = vars->map->i;
	}
	if (check_way(vars, vars->santa->x, vars->santa->y, map_copy(vars)) == 2)
		return (perror("invalid way"));
	vars->santa->x = vars->santa->x * 80;
	vars->santa->y = vars->santa->y * 80;
}

int	parse_map(t_vars *vars)
{
	if (vars->map->i == 0 || vars->map->i == map_height(vars) - 1 || vars->map->j == 0 || vars->map->j == ft_strlen(vars->map->tab[vars->map->i]) - 1)
	{
		if (ft_strchr("1", vars->map->tab[vars->map->i][vars->map->j]) == NULL)
			return (perror("must be wall"), 1);
	}
	else
	{
		if (ft_strchr("01CEP", vars->map->tab[vars->map->i][vars->map->j]) == NULL)
			return (perror("map must be 0, 1, C, E or P"), 1);
	}
	return (0);
}

void	check_map(t_vars *vars)
{
	vars->map->i = -1;
	vars->map->e = 0;
	vars->map->p = 0;
	vars->map->c = 0;
	while (vars->map->tab[++(vars->map->i)])
	{
		vars->map->j = -1;
		while (vars->map->tab[vars->map->i][++(vars->map->j)])
		{
			if (ft_strchr("E", vars->map->tab[vars->map->i][vars->map->j]) != NULL)
				vars->map->e++;
			if (ft_strchr("P", vars->map->tab[vars->map->i][vars->map->j]) != NULL)
				vars->map->p++;
			if (ft_strchr("C", vars->map->tab[vars->map->i][vars->map->j]) != NULL)
				vars->map->c++;
			if (vars->map->e > 1 || vars->map->p > 1)
				return (perror("must have only 1 exit E and 1 player P"), exit (1));
			if (parse_map(vars) == 1)
				return ;
		}
	}
	if (vars->map->c < 1 || vars->map->e < 1 || vars->map->p < 1)
		return (perror("must have 1 exit, 1 player and least 1 collectible C"), exit (1));
	check_P_pos(vars);
}

char	**check_rectangular(char **argv, t_vars *vars)
{
	int		i;
	int		j;
	int		k;

	vars->map->tab = stock_map_tab(argv);
	i = 0;
	j = ft_strlen(vars->map->tab[i]);
	while (vars->map->tab[i])
	{
		k = ft_strlen(vars->map->tab[i]);
		if (k != j)
			return (perror("map's must be rectangular"), NULL);
		i++;
	}
	check_map(vars);
	return (vars->map->tab);	
}
