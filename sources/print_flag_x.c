/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:28:50 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/19 20:20:21 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	print_flag_x(t_flag *flag, va_list *arguments)
{
	uintmax_t	i;

	if (flag->l)
		i = (unsigned long)va_arg(*arguments, unsigned long int);
	else if (flag->ll)
		i = (unsigned long long)va_arg(*arguments, unsigned long long int);
	else if (flag->h)
		i = (unsigned short)va_arg(*arguments, unsigned int);
	else if (flag->hh)
		i = (unsigned char)va_arg(*arguments, unsigned int);
	else
		i = (unsigned int)va_arg(*arguments, unsigned int);
	flag->str = ft_itoa_base_long(i, 16);
	if (flag->flag_5 == 'x')
		flag->str = ft_str_lower(flag->str);
	else
		flag->str = ft_str_upper(flag->str);
	return (printer(flag, i));
}
