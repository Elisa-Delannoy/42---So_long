/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:09:53 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/15 18:09:53 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

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
// 	ft_lstadd_front(lst, lstclst01);
// 	ft_lstadd_front(lst, lstclst04);
// 	ft_lstadd_front(lst, lstclst03);
// 	printf("dernier = %s\n", (char *)ft_lstlast(*lst)->content);
// }
