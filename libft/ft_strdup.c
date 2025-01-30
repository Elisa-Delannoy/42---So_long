/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:17:50 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/08 13:17:51 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*returns a pointer to a new string which is a duplicate of the string s
Memory for the new string is obtained with malloc, and can be freed with free
function returns a pointer to the duplicated string.  It returns NULL if 
insufficient  memory  was  availabl*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	new = malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

// int	main()
// {
// 	char	*test;

// 	test = ft_strdup("bonjournee");
// 	if (new == NULL)
//		return (1);
// 	printf("%s", test);
// 	free(test);
// }