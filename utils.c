/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:42:10 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/21 16:03:35 by edelanno         ###   ########.fr       */
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
