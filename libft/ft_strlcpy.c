/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:39:56 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/06 09:39:57 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*copy strings take the full size  of  the  buffer (not just the length) and
guarantee to NUL-terminate the result(as long as size  is  larger than 0
 Note  that  a  byte for the NUL should be included in size.
  strlcpy()  src  must  be   NUL-terminated
  The  strlcpy() function copies up to size - 1 charac‐
       ters from the NUL-terminated string src to dst,  NUL-
       terminating the result.*/
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <bsd/string.h>
// #include <stdio.h>
// int	main()
// {
// 	char	src[] = "bonjour";
// 	char	dest[15] = "h";
// 	int		a;

// 	a = ft_strlcpy(dest, src, 2);
// 	printf("%s\n", dest);
// 	printf("%d\n", a);
// }
