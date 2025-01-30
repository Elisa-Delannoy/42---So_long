/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:58:36 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/05 14:58:37 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s)
		return (d);
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	return (d);
}

// #include <stdio.h>
// int	main()
// {
// 	char	src[]= "b";
// 	char	dest[50] = "a";
// 	ft_memcpy((void *)dest, (void *)src, 0);
// 	printf("ft =%s\n", dest);
// }
