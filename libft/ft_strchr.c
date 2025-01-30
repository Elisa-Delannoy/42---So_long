/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:42:39 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/07 11:42:41 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*returns a pointer to the first occurrence of the char c in the string s*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	printf("%s", ft_strchr("bonjour", 'n'));
// }
