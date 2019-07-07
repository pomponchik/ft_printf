/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:28:38 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/15 19:09:50 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	printer(t_flag *flag, uintmax_t i)
{
	size_t	temp;
	size_t	len;

	temp = 0;
	len = 0;
	if (flag->flag_5 != '%')
		first_flag_before(i, flag);
	if (flag->flag_5 == 'p')
		fixer_p(flag);
	if (flag->flag_5 == 's' || flag->flag_5 == 'c')
		fixer_str(flag, &len);
	else
		fixer_num(flag);
	if (!flag->ind_c)
	{
		temp = ft_strlen(flag->str);
		ft_lstadd(&(flag->lst), ft_lstnew_no_copy(flag->str, temp));
	}
	else
		ft_lstadd(&(flag->lst), ft_lstnew_no_copy(flag->str, len));
	return (temp);
}
