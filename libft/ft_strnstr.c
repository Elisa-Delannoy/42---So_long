/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:12:12 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/07 18:12:13 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*locates the first occurrence of the null-terminated string little in the
string big, where not more than len characters are searched.Characters that 
appear after a ‘\0’ character are not searched.
If little is an empty string, big is returned; if little occurs nowhere in big,
NULL is returned; otherwise a pointer to the first character of the first 
occurrence of little is returned */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	j = 0;
	while (big[j] && len > 0)
	{
		while (big[j] == little[i] && little[i] && j < len)
		{
			j++;
			i++;
			if (little[i] == '\0')
				return ((char *)(big + j - i));
			if (big[j] != little[i])
			{
				j = j - i +1;
				i = 0;
			}
		}
		j++;
	}
	return (NULL);
}
// #include <bsd/string.h>
// #include <stdio.h>
// -lbsd
// int	main()
// {
// 	char big[50] = "feuhaairgntaaabcabcd";
// 	char little[50] = "aabcabcd";
// 	int		num;

// 	num = -1;
// 	printf("moi =%s\n", ft_strnstr(big, little, num));
// 	printf("vrai=%s", strnstr(big, little, num));
// }
