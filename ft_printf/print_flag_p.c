/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:18:57 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/19 20:19:49 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	print_flag_p(t_flag *flag, va_list *arguments)
{
	uintmax_t	p;
	size_t		temp;

	p = (unsigned long)va_arg(*arguments, unsigned long int);
	flag->ll = 0;
	flag->l = 1;
	flag->str = ft_strdup("0x");
	if (!(flag->dot && p == 0))
		flag->str = ft_strjoin_free_1(flag->str, ft_itoa_base_long(p, 16));
	temp = ft_strlen(flag->str);
	flag->str = ft_str_lower(flag->str);
	return (printer(flag, 1));
}
