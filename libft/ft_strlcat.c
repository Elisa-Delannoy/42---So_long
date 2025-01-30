/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:21:08 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/06 11:21:09 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*concatenate strings, a byte for the NUL should be included in size.*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	k = (ft_strlen(src) + ft_strlen(dst));
	if (size < (i + 1))
		return (ft_strlen(src) + size);
	else
	{
		j = 0;
		while (i < (size - 1) && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	dst[i] = '\0';
	return (k);
}

// #include <bsd/string.h>
// #include <string.h>
// int	main()
// {
// 	char	src[] = "banane";
// 	char	dest[12] = "hello";
// 	int		a;
// 	int		size;
// 	size = 8;
// 	a = strlcat(dest, src, size);
// 	printf("%s\n", dest);
// 	printf(" %d\n", a);
// }
