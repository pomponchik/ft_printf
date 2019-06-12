/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:31:12 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:16:24 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	print_flag_u(t_flag *flag, va_list *arguments)
{
	uintmax_t	i;

	if (flag->l || flag->flag_5 == 'U')
		i = (unsigned long)va_arg(*arguments, unsigned long int);
	else if (flag->ll)
		i = (unsigned long long)va_arg(*arguments, unsigned long long int);
	else if (flag->hh)
		i = (unsigned char)(va_arg(*arguments, unsigned int));
	else if (flag->h)
		i = (unsigned short)(va_arg(*arguments, unsigned int));
	else
		i = (unsigned int)va_arg(*arguments, unsigned int);
	flag->str = ft_itoa_llu(i);
	flag->plus = 0;
	return (printer(flag, i));
}
