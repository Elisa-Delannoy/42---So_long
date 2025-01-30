/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:49:27 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/15 11:49:27 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*newcontent;

	newcontent = malloc(sizeof(t_list));
	if (newcontent == NULL)
		return (NULL);
	newcontent->next = NULL;
	newcontent->content = content;
	return (newcontent);
}
// #include <stdio.h>
// int	main()
// {
// 	t_list	*a;
// 	a = ft_lstnew("hello");
// 	printf("content = %s\n", (char *)a->content);
// 	printf("next = %s", (char *)a->next);
// 	free (a);
// }