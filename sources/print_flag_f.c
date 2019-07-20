/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:33:34 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:12:32 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	print_flag_f(t_flag *flag, va_list *arguments)
{
	long double	i;

	if (flag->ll)
		i = va_arg(*arguments, long double);
	else
		i = va_arg(*arguments, double);
	if (flag->after_flag)
		flag->str = ft_itoa_specific(i, flag->after_dot);
	else
		flag->str = ft_itoa_specific(i, 6);
	return (printer(flag, i));
}
