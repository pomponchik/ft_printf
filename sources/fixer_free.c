/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixer_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:56:17 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 19:15:15 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void		fixer_free_helpers_helper(t_flag *f, int s)
{
	char		a;
	char		*temp;

	a = *(f->str);
	temp = f->str;
	f->str = ft_str_width_free(f->str + 1, '0', s - 1, "left, no");
	free(temp);
	f->str = ft_strjoin_free_1(ft_strdup_n(&a, 1), f->str);
}

static void		fixer_free_helper(t_flag *f, int s)
{
	char		*temp;

	if ((f->sharp && (f->flag_5 == 'x' || f->flag_5 == 'X')) ||
		*(f->str) == '+' || *(f->str) == '-' || *(f->str) == ' ')
	{
		if (*(f->str) == '+' || *(f->str) == '-' || *(f->str) == ' ')
			fixer_free_helpers_helper(f, s);
		else
		{
			temp = f->str;
			f->str = ft_str_width_free(f->str + 2, '0', s - 2, "left, no");
			free(temp);
			if (f->flag_5 == 'X')
				f->str = ft_strjoin_free_2("0X", f->str);
			else
				f->str = ft_strjoin_free_2("0x", f->str);
		}
	}
	else
		f->str = ft_str_width_free(f->str, '0', s, "left, no");
}

void			fixer_free(t_flag *f, int min, int null, int s)
{
	if (min && null)
		f->str = ft_str_width_free(f->str, '0', s, "right, no");
	else if (min && !(null))
		f->str = ft_str_width_free(f->str, ' ', s, "right, no");
	else if (null && !(min))
		fixer_free_helper(f, s);
	else
		f->str = ft_str_width_free(f->str, ' ', s, "left, no");
}
