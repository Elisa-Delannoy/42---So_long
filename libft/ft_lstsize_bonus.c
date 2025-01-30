/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:18 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/15 15:50:18 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// #include <stdio.h>
// int	main()
// {
// 	t_list	**lst;
// 	t_list	*lstclst01;
// 	t_list	*lstclst02;
// 	t_list	*lstclst03;

// 	lstclst02 = ft_lstnew("bonjour");
// 	printf("%p\n", lstclst02);
// 	lstclst01 = ft_lstnew("hello");
// 	printf("%p\n", lstclst01);
// 	lstclst03 = ft_lstnew("test");
// 	printf("%p\n", lstclst03);
// 	lst = &lstclst02;
// 	ft_lstadd_front(lst, lstclst01);
// 	ft_lstadd_front(lst, lstclst03);
// 	printf("%p\n", *lst);
// 	printf("size = %d\n", ft_lstsize(*lst));
// }