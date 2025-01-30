/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:17:04 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/08 11:17:05 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*allocates memory for an array of nmemb elements of size bytes each and 
returns a pointer to the allocated memory. memory is set to zero
If nmemb or size is 0, then calloc() returns either NULL, or a unique pointer 
value that can later be successfully passed to free(). If the multiplication of 
nmemb and size would result in integer overflow, then calloc() returns an error
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb * size != 0 && nmemb * size / size != nmemb)
		return (NULL);
	array = (void *)malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, nmemb * size);
	return (array);
}

// #include <stdio.h>
// int	main()
// {
// 	size_t	i;
// 	size_t	nmemb;
// 	char	*arraytest;
// 	char	*arraytest2;

// 	nmemb = 0;
// 	arraytest = (char *)ft_calloc( nmemb, sizeof(char));
// 	arraytest2 = (char *)calloc( nmemb, sizeof(char));
// 	i = 0;
// 	if (arraytest == NULL)
// 		return (1);
// 	while (i < (nmemb * sizeof(char)))
// 	{
// 		printf("my ft_calloc =%02x\n", arraytest[i]);
// 		printf("calloc =%02x\n", arraytest2[i]);
// 		i++;
// 	}
// }