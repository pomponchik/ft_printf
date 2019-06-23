/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:53:24 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/15 18:59:38 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	ok(char *str, t_flag *flag, va_list *arguments)
{
	size_t	num;

	num = 0;
	if (flag_begin_chek(&str[num], flag))
		num += flag_begin_chek(&str[num], flag);
	if (second_flag(&str[num], flag) && !flag->dot)
 		num += ft_math_numlen_long((long int)flag->before_dot);
	else if (str[num] == '.')
	{
		flag->dot = 1;
			num++;
		if (str[num] > '0' && str[num] <= '9')
		{
			flag->after_dot = ft_atoi(str + num);
			num += ft_math_numlen_long((long int)flag->after_dot);
		}
		if (str[num] == '*')
		{
			flag->after_dot = va_arg(*arguments, int);
			num++;
		}
	}
	else if (str[num] == '*' && !flag->dot)
	{
		flag->before_dot = va_arg(*arguments, int);
		num++;
	}
	num += size_flag(&str[num], flag, num);
	if (!flag_end(str[num]))
		return (ok(&str[num], flag, arguments));
	return (num);
}
