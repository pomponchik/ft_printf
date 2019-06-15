/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:49:02 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/15 18:29:56 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_printf(const char *format, ...)
{
	char	*str;
	char	*t;
	int		p_indicate;
	va_list	arguments;
	t_list	*lst;
	size_t	s;

	if (!format)
		return (0);
	lst = NULL;
	str = (char *)format;
	va_start(arguments, format);
	if (!*str)
		return (0);
	while (*str)
	{
		p_indicate = 0;
		s = just_to_print_len(str, &p_indicate, &lst);
		if (s && p_indicate == 0)
			ft_lstadd(&lst, ft_lstnew_without_copy((t = ft_strdup_n(str, s)), s));
		str += s;
		if (p_indicate == 1)
			str += post_persent(str + 1, &arguments, &lst);
	}
	va_end(arguments);
	return (ft_lst_putstr_free_cs(ft_lst_turn(lst)));
}
