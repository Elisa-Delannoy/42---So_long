/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:42:10 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/14 18:42:12 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


size_t	map_height(t_var *var)
{
	var->map->width = ft_strlen(var->map->tab[0]) - 1;
	var->map->height = 0;
	while (var->map->tab[var->map->height])
		var->map->height++;
	return (var->map->height);
}

void	free_tab(t_var *var, char **tab)
{
	size_t	i;

	map_height(var);
	i = 0;
	while (i < var->map->height)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
