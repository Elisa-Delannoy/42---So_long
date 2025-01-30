/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:49:30 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/13 18:49:31 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	i = 0;
	new = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

// #include <stdio.h>
// char	ft_tolowertest(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 65 && c <= 90)
// 		c = c + 32;
// 	return (c);
// }
// int main()
// {
// 	printf("%s", ft_strmapi("BoOJOUr", ft_tolowertest));
// }