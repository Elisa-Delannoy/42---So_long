/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:42:23 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/07 16:42:24 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*scans the initial n bytes of the memory area pointed to by s for the first
instance of c
return a pointer to the matching byte or NULL if the character does not occur 
in the given  memory area.*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

// int	main()
// {
// 	printf("%s", (char *)ft_memchr("bonjour", 'o', 2));
// }
