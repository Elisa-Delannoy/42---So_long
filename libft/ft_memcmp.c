/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:33:40 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/07 17:33:41 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
compares the first n bytes (each interpreted as unsigned char) of the memory 
areas s1 and s2
returns an integer less than, equal to, or greater than zero if the first n 
bytes of s1 is found, respectively, to be less than, to match, or be greater 
than the first n bytes of s2.
If n is zero, the return value is zero.*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (((i + 1) < n) && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}

// int	main()
// {
// 	size_t	n;

// 	n = 0;
// 	printf("%d\n", memcmp("bonjour", "bonjous", n));
// 	printf("ft=%d\n", ft_memcmp("bonjour", "bonjous", n));
// }
