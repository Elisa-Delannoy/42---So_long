/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:18:12 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/13 19:18:13 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// void	ft_tolowertest(unsigned int i, char *c)
// {
// 	(void)i;
// 	if (*c >= 65 && *c <= 90)
// 		*c = *c + 32;
// }
// int	main()
// {
// 	char	s[] = "BOnjouR";

// 	ft_striteri(s, ft_tolowertest);
// 	printf("%s", s);
// }