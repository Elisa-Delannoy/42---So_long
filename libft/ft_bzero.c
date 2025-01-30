/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:38:35 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/05 13:39:25 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*erases the data in the n bytes of the memory starting at the location 
pointed to by s, by writing zeros (bytes containing '\0') to that area.*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*new;

	i = 0;
	new = (unsigned char *)s;
	while (i < n)
	{
		new[i] = '\0';
		i++;
	}
}

// #include <stdio.h>
// int	main()
// {
// 	char	p[] = "bonjour";
// 	char	test[] = "bonjour";

// 	printf("my ft_bzero before :%s\n", p);
// 	ft_bzero((void *)p, 3);
// 	printf("my ft_bzero after :%s\n", p);
// 	printf("bzero before :%s\n", test);
// 	bzero((void *)test, 3);
// 	printf("bzero after :%s\n", test);
// }