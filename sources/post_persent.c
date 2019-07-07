/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_persent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:43:12 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/15 18:04:24 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	post_persent(char *str, va_list *arguments, t_list **lst)
{
	t_flag	flag;
	size_t	type_len;
	size_t	out_len;

	type_len = 0;
	flag_nuller(&flag);
	flag.lst = *lst;
	if (!(type_len += check_flags(str, &flag)))
		return (1);
	else
		out_len = out_from_flag(&flag, arguments);
	*lst = flag.lst;
	return (type_len + 1);
}
