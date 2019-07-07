/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixer_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:01:09 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 19:09:04 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	fixer_num_helper(t_flag *f, int *len, int c)
{
	if (*len >= f->after_dot)
		f->after_dot = 0;
	if (f->after_dot)
	{
		if (f->after_dot > f->before_dot)
			f->before_dot = 0;
		if (f->flag_5 == 'd' || f->flag_5 == 'i' || f->flag_5 == 'o' ||
			f->flag_5 == 'u' || f->flag_5 == 'x' || f->flag_5 == 'X')
		{
			if (*(f->str) == '-' || *(f->str) == '+' || *(f->str) == ' ')
				f->after_dot++;
			if ((f->flag_5 == 'x' || f->flag_5 == 'X') && *len == 3)
				f->after_dot += 2;
			fixer(f, 0, 1, f->after_dot);
			f->null = 0;
			c++;
		}
		else
			fixer(f, f->min, f->null, f->after_dot);
	}
	return (c);
}

int			fixer_num(t_flag *f)
{
	int		len;
	int		c;

	c = 0;
	len = ft_strlen(f->str);
	if (f->space || f->plus)
		len--;
	if (len >= f->before_dot && len >= f->after_dot)
		return (0);
	if (f->flag_5 == '%' && f->before_dot == 0)
	{
		f->str = ft_strdup("%");
		return (0);
	}
	c = fixer_num_helper(f, &len, c);
	if (c)
		fixer_free(f, f->min, f->null, f->before_dot);
	else
		fixer(f, f->min, f->null, f->before_dot);
	return (0);
}
