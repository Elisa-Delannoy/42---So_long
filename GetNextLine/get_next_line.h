/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:18:27 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/21 15:18:28 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# if BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE 
#  define BUFFER_SIZE 1000000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_temp(char **newbuffer, char *buffer, int i);
char	*ft_read(int fd, char *buffer, char **newbuffer);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
