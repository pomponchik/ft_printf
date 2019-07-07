/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:13:00 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:11:38 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	print_flag_d(t_flag *flag, va_list *arguments)
{
	intmax_t i;

	if (flag->l || flag->flag_5 == 'D')
		i = (long)va_arg(*arguments, long int);
	else if (flag->ll)
		i = (long long)va_arg(*arguments, long long int);
	else if (flag->hh)
		i = (signed char)va_arg(*arguments, int);
	else if (flag->h)
		i = (short)va_arg(*arguments, int);
	else
		i = (int)va_arg(*arguments, int);
	free(flag->str);
	flag->str = ft_itoa_long_long(i);
	return (printer(flag, i));
}
