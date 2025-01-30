/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:20:42 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/13 13:20:43 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnbstring(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**tab;
	size_t	start;
	size_t	end;

	tab = (char **) malloc ((ft_countnbstring(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (end > start)
			tab[j++] = ft_substr(s, start, end - start);
	}
	tab[j] = 0;
	return (tab);
}

// #include <stdio.h>
// int	main()
// {
// 	char **tab1 = ft_split("bonjour bonjour bonjour", ' ');
// 	int	j;

// 	j = 0;
// 	while (j < ft_countnbstring("bonjour bonjour bonjour", ' ') + 1)
// 	{
// 		printf("tab j = %s\n", tab1[j]);
// 		free(tab1[j]);
// 		j++;
// 	}
// 	free(tab1);
// }
