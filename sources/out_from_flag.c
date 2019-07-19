/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_from_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:38:54 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:05:59 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	out_from_flag(t_flag *f, va_list *arguments)
{
	if (f->flag_5 == 'p')
		return (print_flag_p(f, arguments));
	else if (f->flag_5 == 'x' || f->flag_5 == 'X')
		return (print_flag_x(f, arguments));
	else if (f->flag_5 == 'o' || f->flag_5 == 'O')
		return (print_flag_o(f, arguments));
	else if (f->flag_5 == 'u' || f->flag_5 == 'U')
		return (print_flag_u(f, arguments));
	else if (f->flag_5 == 'd' || f->flag_5 == 'i' || f->flag_5 == 'D')
		return (print_flag_d(f, arguments));
	else if (f->flag_5 == 'f' || f->flag_5 == 'F')
		return (print_flag_f(f, arguments));
	else if (f->flag_5 == 's' || f->flag_5 == 'c' ||
	f->flag_5 == '%' || f->flag_5 == 'g')
		return (print_flag_sc(f, arguments));
	else if (f->flag_5 == 'q' || f->flag_5 == 'y' || f->flag_5 == 'e' ||
	f->flag_5 == 'b')
		return (print_flag_bonus(f, arguments));
	return (0);
}
