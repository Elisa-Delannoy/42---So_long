/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:14:06 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/08 10:14:07 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*converts the initial portion of the string pointed to by nptr to int
does not detect errors -- return the converted value or 0 on error.*/

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	i;
	int	m;

	nb = 0;
	i = 0;
	m = 1;
	if ((nptr[i] < '0' && nptr[i] > '9') && nptr[i] != '+' && nptr[i] != '-'
		&& !((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			m = -m;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	return (nb * m);
}

// int	main()
// {
// 	printf("%d\n", ft_atoi("2147483647"));
// 	printf("%d\n", atoi("2147483647"));
// }
