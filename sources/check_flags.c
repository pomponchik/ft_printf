/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:59:56 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/20 17:23:20 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	bonus_part(char *s, t_flag *flag)
{
	if (ft_strnstr(s, "list", 4))
	{
		flag->flag_5 = 'q';
		return (4);
	}
	if (ft_strnstr(s, "file", 4))
	{
		flag->flag_5 = 'y';
		return (4);
	}
	if (ft_strnstr(s, "dlist", 5))
	{
		flag->flag_5 = 'e';
		return (5);
	}
	if (*s == 'c' || *s == 'f' || *s == 'd' || *s == 's' || *s == 'i' ||
		*s == 'o' || *s == 'u' || *s == 'x' || *s == 'X' || *s == 'p' ||
		*s == 'b' || *s == '%' || *s == 'U' || *s == 'D' || *s == 'O' ||
		*s == 'F' || *s == 'g')
	{
		flag->flag_5 = *s;
		return (1);
	}
	return (0);
}

size_t	check_flags(char *str, t_flag *flag)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (flag_end(&str[index]))
		{
			index += bonus_part(&str[index], flag);
			if (flag->ll && (flag->flag_5 == 'O' || flag->flag_5 == 'U' ||
			flag->flag_5 == 'D'))
			{
				flag->hh = 0;
				flag->h = 1;
			}
			break ;
		}
		else if (ok(str + index, flag))
			index += ok(str + index, flag);
		else
			return (index);
	}
	if (!only_1_flag(flag))
		return (index);
	return (index);
}
