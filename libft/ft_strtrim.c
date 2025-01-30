/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:26:56 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/12 16:26:57 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compsetbefore(char const *s1, char const *set)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (set[i])
	{
		if (s1[j] == set[i])
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

static int	ft_compsetafter(char const *s1, char const *set)
{
	int		i;
	int		j;

	j = ft_strlen(s1) - 1;
	i = 0;
	while (set[i])
	{
		if (s1[j] == set[i])
		{
			j--;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;

	start = ft_compsetbefore(s1, set);
	len = ft_compsetafter(s1, set) - start + 1;
	return (ft_substr(s1, start, len));
}

// #include <stdio.h>
// int	main()
// {
// 	printf("before%d\n", ft_compsetbefore("    ", " "));
// 	printf("after%d\n", ft_compsetafter("    ", " "));
// 	printf("ft =%s", ft_strtrim("    ", " "));
// }
