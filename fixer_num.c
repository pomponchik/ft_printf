/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixer_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:01:09 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 17:01:50 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	fixer_num(t_flag *flag)
{
	int	len;
	int	c;

	c = 0;
	len = ft_strlen(flag->str);
	if (flag->space || flag->plus)
		len--;
	if (len >= flag->before_dot && len >= flag->after_dot)
		return (0);
	if (flag->flag_5 == '%' && flag->before_dot == 0)
	{
		flag->str = ft_strdup("%");
		return (0);
	}
	if (len >= flag->after_dot)
		flag->after_dot = 0;
	if (flag->after_dot)
	{
		if (flag->after_dot > flag->before_dot)
			flag->before_dot = 0;
		if (flag->flag_5 == 'd' || flag->flag_5 == 'i' || flag->flag_5 == 'o' ||
			flag->flag_5 == 'u' || flag->flag_5 == 'x' || flag->flag_5 == 'X')
		{
			if (*(flag->str) == '-' || *(flag->str) == '+' || *(flag->str) == ' ')
				flag->after_dot++;
			if ((flag->flag_5 == 'x' || flag->flag_5 == 'X') && len == 3)
				flag->after_dot += 2;
			fixer(flag, 0, 1, flag->after_dot);
			flag->null = 0;
			c++;
		}
		else
			fixer(flag, flag->min, flag->null, flag->after_dot);
	}
	if (c)
		fixer_free(flag, flag->min, flag->null, flag->before_dot);
	else
		fixer(flag, flag->min, flag->null, flag->before_dot);
	return (0);
}
