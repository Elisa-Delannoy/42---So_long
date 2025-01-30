/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:04:09 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/13 17:04:11 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenint(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		if (n == 0)
			return (1);
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		len;
	long	nb;

	nb = n;
	len = ft_lenint(nb);
	tab = malloc ((len + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	tab[len] = '\0';
	if (nb == 0)
		tab[0] = 48;
	if (nb < 0)
	{
		tab[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		tab[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (tab);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%s", ft_itoa(-123569));
// }