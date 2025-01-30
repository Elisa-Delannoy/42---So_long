/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:37:42 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/15 18:37:47 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
// new->next = NULL; ne pas ajouter acr deja fait en creation lst
// #include <stdio.h>
// int	main()
// {
// 	t_list	**lst;
// 	t_list	*lstclst01;
// 	t_list	*lstclst02;
// 	t_list	*lstclst03;
// 	t_list	*lstclst04;

// 	lstclst02 = ft_lstnew("bonjour");
// 	lstclst01 = ft_lstnew("hello");
// 	lstclst03 = ft_lstnew("test");
// 	lstclst04 = ft_lstnew("avant test");
// 	lst = &lstclst02;
// 	ft_lstadd_back(lst, lstclst03);
// 	ft_lstadd_back(lst, lstclst01);
// 	printf("last = %s\n", (char *)ft_lstlast(*lst)->content);
// }
