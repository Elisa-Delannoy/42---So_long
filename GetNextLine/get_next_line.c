/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:44:30 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/21 15:44:32 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_temp(char **newbuffer, char *buffer, int i)
{
	char	*temp;

	if (i < 0)
	{
		temp = ft_strjoin(*newbuffer, buffer);
		if (temp == NULL)
			return (NULL);
		if (*newbuffer != NULL)
			free (*newbuffer);
		*newbuffer = temp;
	}
	if (i >= 0)
	{
		temp = ft_strdup(*newbuffer + i + 1);
		if (temp == NULL)
			return (NULL);
		if (*newbuffer != NULL)
			free (*newbuffer);
		*newbuffer = temp;
	}
	if (*newbuffer == NULL)
		return (NULL);
	return (*newbuffer);
}

char	*ft_read(int fd, char *buffer, char **newbuffer)
{
	int	m;

	m = 1;
	while (m != 0 && ft_strchr(*newbuffer, '\n') == NULL)
	{
		m = read (fd, buffer, BUFFER_SIZE);
		if (m == -1)
		{
			if (*newbuffer != NULL)
				free(*newbuffer);
			return (NULL);
		}
		buffer[m] = '\0';
		*newbuffer = ft_temp(newbuffer, buffer, -1);
	}
	if (m == 0 && *newbuffer[0] == '\0')
	{
		free (*newbuffer);
		return (NULL);
	}
	if (m == 0 && *newbuffer && *newbuffer[0] != '\0')
		return (*newbuffer);
	return (*newbuffer);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*newbuffer = NULL;
	char		*content;
	int			i;

	buffer[0] = '\0';
	newbuffer = ft_read(fd, buffer, &newbuffer);
	if (newbuffer == NULL)
		return (NULL);
	content = ft_calloc ((ft_strlen(newbuffer) + 1), sizeof(char));
	if (content == NULL)
		return (free(newbuffer), NULL);
	i = -1;
	while (newbuffer[++i] && newbuffer[i] != '\n')
		content[i] = newbuffer[i];
	if (newbuffer[i] == '\0')
		newbuffer = ft_temp(&newbuffer, newbuffer, i - 1);
	else if (newbuffer[i] == '\n')
	{
		newbuffer = ft_temp(&newbuffer, newbuffer, i);
		content[i++] = '\n';
	}
	return (content[i] = '\0', content);
}

// # include <sys/types.h>
// # include <sys/stat.h>
// # include <fcntl.h>

// int main()
// {
//     int fd = open("test.txt", O_RDONLY); 
//     int i = 0;

//     while (i < 6)
//     {
//         char *line = get_next_line(fd); 
//         if (line) {
//             printf("i = %i line = %s\n", i, line);
//             free(line);
//         }
//         i++;
//     }
//     close(fd);
//     return 0;
// }
