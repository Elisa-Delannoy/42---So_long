/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:44:30 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/07 15:44:32 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*compares  the two strings s1 and s2, 0, if the s1 and s2 are equal
negative value  if  s1 is less than s2; positive value if s1 is  greater
than s2.*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && (n > (i + 1)) && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main()
// {
// 	printf("%d\n", strncmp("abcdef", "abc\375bxx", 3));
// 	printf("ft=%d\n", ft_strncmp("abcdef", "abc\375xx", 3));
// }
