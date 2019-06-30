/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:49:02 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 17:57:30 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_printf(const char *format, ...)
{
	t_printf i;

	if (!format)
		return (0);
	i.lst = NULL;
	i.str = (char *)format;
	va_start(i.arguments, format);
	if (!*(i.str))
		return (0);
	while (*(i.str))
	{
		i.p_indicate = 0;
		i.s = just_to_print_len(i.str, &i.p_indicate, &i.lst);
		if (i.s && i.p_indicate == 0)
			ft_lstadd(&i.lst, ft_lstnew_no_copy((i.t = \
				ft_strdup_n(i.str, i.s)), i.s));
		i.str += i.s;
		if (i.p_indicate == 1)
			i.str += post_persent(i.str + 1, &i.arguments, &i.lst);
	}
	va_end(i.arguments);
	return (ft_lst_putstr_free_cs(ft_lst_turn(i.lst)));
}
