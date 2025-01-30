/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:04:24 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/15 14:04:25 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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
// 	printf("%p\n", lstclst02);
// 	lstclst01 = ft_lstnew("hello");
// 	printf("%p\n", lstclst01);
// 	lstclst03 = ft_lstnew("test");
// 	lstclst04 = ft_lstnew("avant test");
// 	printf("%p\n", lstclst03);
// 	lst = &lstclst02;
// 	printf("%p\n", *lst);
// 	ft_lstadd_front(lst, lstclst01);
// 	ft_lstadd_front(lst, lstclst04);
// 	ft_lstadd_front(lst, lstclst03);
// 	printf("%p\n", *lst);
// 	while (*lst)
// 	{
// 		printf("%s\n", (char *)(*lst)->content);
// 		*lst = (*lst)->next;
// 	}
// }