/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 23:36:49 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/18 23:37:03 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char		*lst_print_cs(void *point)
{
	t_list	*lst;
	t_list	*result;

	lst = (t_list *)point;
	if (!lst)
		return (ft_strdup("[NULL]"));
	result = ft_lstnew("[", 1);
	while (lst)
	{
		if (lst->content)
			ft_lstadd(&result, ft_lstnew(lst->content, lst->content_size));
		else
			ft_lstadd(&result, ft_lstnew("(NULL)", 6));
		if (lst->next)
			ft_lstadd(&result, ft_lstnew("]->[", 4));
		lst = lst->next;
	}
	ft_lstadd(&result, ft_lstnew("]", 1));
	return (ft_lst_strjoin_free_cs(ft_lst_turn(result)));
}

char		*lst_print_deduplication(void *point)
{
	t_list	*lst;

	lst = (t_list *)point;
	if (!lst)
		return (ft_strdup("[NULL]"));
	lst = ft_lst_deduplication(lst);
	return (lst_print_cs(lst));
}
