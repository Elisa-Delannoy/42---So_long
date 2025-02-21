/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:38:17 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/20 20:23:26 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char **argv)
{
	char	*name;

	name = ft_strrchr(argv[1], '.');
	if (name == NULL)
		return (ft_putstr_fd("map's name must end with .ber\n", 2), 1);
	printf("%s\n", name);
	if (ft_strncmp(".ber", name, 4) != 0 || ft_strlen(name) != 4)
		return (ft_putstr_fd("map's name must end with .ber\n", 2), 1);
	return (0);
}

t_list	*open_read(char **argv)
{
	int		fd;
	char	*line;
	t_list	*map_line;
	t_list	*map;

	map = NULL;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (line[ft_strlen(line) - 1] == '\r')
			line[ft_strlen(line) - 1] = '\0';
		map_line = ft_lstnew(line);
		ft_lstadd_back(&map, map_line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}

char	**stock_map_tab(char **argv)
{
	t_list		*map;
	t_list		*temp;
	char		**tab;
	int			i;

	map = open_read(argv);
	if (!map)
		return (NULL);
	temp = map;
	tab = malloc(sizeof(char *) * (ft_lstsize(map) + 1));
	if (tab == NULL)
	{
		ft_lstclear(&map, free);
		return (NULL);
	}
	i = 0;
	while (temp)
	{
		tab[i] = ft_strdup((char *)temp->content);
		i++;
		temp = temp->next;
	}
	tab[i] = NULL;
	ft_lstclear(&map, free);
	return (tab);
}

int	check_rectangular(char **argv, t_var *var)
{
	int		i;
	int		j;
	int		k;

	if (check_name(argv) == 1)
		return (1);
	var->map->tab = stock_map_tab(argv);
	if (!var->map->tab)
		return (ft_putstr_fd("map's empty\n", 2), 1);
	map_height(var);
	i = 0;
	j = ft_strlen(var->map->tab[i]);
	while (var->map->tab[i])
	{
		k = ft_strlen(var->map->tab[i]);
		if (k != j)
			return (ft_putstr_fd("map's must be rectangular\n", 2), 1);
		i++;
	}
	if (check_map(var) == 1)
		return (1);
	return (0);
}
