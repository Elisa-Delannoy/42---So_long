/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:14:03 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/12 14:14:04 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*string from s starting by start and max len*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*new;

	i = 0;
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc((len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (*s && i < (len))
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
// #include <stdio.h>
// int	main()
// {
// 	printf("%s", ft_substr("", 0, 0));
// }