/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:58:27 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/04 16:58:28 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*fills the first n bytes of the memory area pointed to by s with the 
constant byte c */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*new;

	i = 0;
	new = (unsigned char *)s;
	while (i < n)
	{
		new[i] = c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// int main( void )
// {
// 	char	buffer[] = "This is a test of the memset function";
// 	printf( "Before: %s\n", buffer );
// 	memset( (void *)buffer, 'j', 4);
// 	printf( "After:  %s\n", buffer +3);
// }
