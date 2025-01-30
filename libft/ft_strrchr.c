/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:36:57 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/07 14:36:58 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*returns a pointer to the last occurrence of the character c in the string s*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + i));
	while (i > 0)
	{
		if (*(s + (i - 1)) == (char)c)
			return ((char *)(s + (i - 1)));
		i--;
	}
	return (NULL);
}

// int	main()
// {
// 	printf("%s", ft_strrchr("bonjour", 'r'));
// }
