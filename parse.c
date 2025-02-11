/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:38:17 by edelanno          #+#    #+#             */
/*   Updated: 2025/02/11 20:56:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char **argv)
{
	char	*name;

	name = ft_strrchr(argv[1], '.');
	if (name == NULL)
		return (perror("map's name must end with .ber"), 1);
	if (ft_strncmp(".ber", name, 4) != 0)
		return (perror("map's name must end with .ber"), 1);
	return (0);
}

t_list	*open_read(char **argv)
{
	int		fd;
	char	*line;
	t_list	*map_line;
	t_list	*map;

	map = NULL;
	if (check_name(argv) != 0)
		return (NULL);
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
	return (map);
}

void	free_tab(int size, char **tab)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**stock_map_tab(char **argv)
{
	t_list		*map;
	t_list		*temp;
	char		**tab;
	int			i;
	int			size;

	map = open_read(argv);
	temp = map;
	size = ft_lstsize(map);
	tab = (char **) malloc((size + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = ft_strdup((char *)temp->content);
		i++;
		temp = temp->next;
	}
	tab[i] = NULL;
	// free_tab(size, tab);
	ft_lstclear(&map, free);
	return (tab);
}

size_t	map_width(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	parse_map(t_map *map, char **tab)
{
	if (map->i == 0 || map->i == map_width(tab) || map->j == 0 || map->j == ft_strlen(tab[map->i]) - 1)
	{
		if (ft_strchr("1", tab[map->i][map->j]) == NULL)
			return (perror("must be wall"), 1);
	}
	else
	{
		if (ft_strchr("01CEP", tab[map->i][map->j]) == NULL)
			return (perror("map must be 0, 1, C, E or P"), 1);
	}
	return (0);
}

void	check_map(t_map *map, char **tab)
{
	map->i = -1;
	map->e = 0;
	map->p = 0;
	map->c = 0;
	while (tab[++(map->i)])
	{
		map->j = -1;
		while (tab[map->i][++(map->j)])
		{
			if (ft_strchr("E", tab[map->i][map->j]) != NULL)
				map->e++;
			if (ft_strchr("P", tab[map->i][map->j]) != NULL)
				map->p++;
			if (ft_strchr("C", tab[map->i][map->j]) != NULL)
				map->c++;
			if (map->e > 1 || map->p > 1)
				return (perror("must have only 1 exit E and 1 player P"));
			if (parse_map(map, tab) == 1)
				return ;
		}
	}
	if (map->c < 1)
		return (perror("must have at least 1 exit collectible C"));
}

char	**check_rectangular(char **argv, t_map *map)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = stock_map_tab(argv);
	i = 0;
	j = ft_strlen(tab[i]);
	while (tab[i])
	{
		k = ft_strlen(tab[i]);
		if (k != j)
			return (perror("map's must be rectangular"), NULL);
		i++;
	}
	if (i == j)
		return (perror("map's must be rectangular not square"), NULL); /*voir si ok carre ou non*/
	check_map(map, tab);
	return (tab);	
}

