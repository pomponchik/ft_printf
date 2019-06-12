/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_begin_chek.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:09:22 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 17:56:53 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t spaces(char *str)
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

size_t	flag_begin_chek(char *a, t_flag *flag)
{
	size_t i;
	size_t temp;

	i = 0;
	temp = 0;
	while (a[i] == '0' || a[i] == '+' || a[i] == '-' || a[i] == ' ' ||
	a[i] == '#')
	{
		if (a[i] == '0')
			flag->null = 1;
		if (a[i] == '+')
			flag->plus = 1;
		if (a[i] == '-')
			flag->min = 1;
		if (a[i] == '#')
			flag->sharp = 1;
		if (a[i] == ' ')
			flag->space = 1;
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
