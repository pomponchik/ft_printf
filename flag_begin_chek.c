/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_begin_chek.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:09:22 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/15 15:45:08 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	spaces(char *str)
{
	size_t result;

	result = 0;
	while (*str && *str == ' ')
	{
		str++;
		result++;
	}
	return (result);
}

void	flag_first(char a, t_flag *flag)
{
	if (a == '0')
		flag->null = 1;
	if (a == '+')
		flag->plus = 1;
	if (a == '-')
		flag->min = 1;
	if (a == '#')
		flag->sharp = 1;
	if (a == ' ')
		flag->space = 1;
}

size_t	flag_begin_chek(char *a, t_flag *flag)
{
	size_t i;
	size_t temp;

	i = 0;
	temp = 0;
	while (a[i] == '0' || a[i] == '+' || a[i] == '-' || a[i] == ' ' ||
	a[i] == '#')
	{
		flag_first(a[i], flag);
		if ((temp = spaces(&a[i])))
		{
			flag->space = 1;
			i += temp;
			temp = 0;
			continue ;
		}
		i++;
	}
	return (i);
}
