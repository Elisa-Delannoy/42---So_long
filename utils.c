/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:42:10 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/18 12:02:30 by edelanno         ###   ########.fr       */
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

void	free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
