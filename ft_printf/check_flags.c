/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:59:56 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 17:55:25 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	check_flags(char *str, t_flag *flag, va_list *arguments)
{
	size_t index;

	index = 0;
	int i = 0;
	while (str[index])
	{
		i++;
		if (flag_end(str[index]))
		{
			flag->flag_5 = str[index];
			index++;
			if (flag->ll && (flag->flag_5 == 'O' || flag->flag_5 == 'U' ||
			flag->flag_5 == 'D'))
			{
				flag->hh = 0;
				flag->h = 1;
			}
			break ;
		}
		else if (ok(str + index, flag, arguments))
			index += ok(str + index, flag, arguments);
		else
			return (index);
	}
	if (!only_1_flag(flag))
				return (index);
	return (index);
}
