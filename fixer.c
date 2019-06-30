/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:58:31 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 19:03:43 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void		fixer_helpers_helper(t_flag *f, int s)
{
	char		a;
	char		*temp;

	a = *(f->str);
	temp = f->str;
	f->str = ft_str_width(f->str + 1, '0', s - 1, "left, no");
	free(temp);
	f->str = ft_strjoin_fr_both(ft_strnew_filler(1, a), f->str);
}

static void		fixer_helper(t_flag *f, int s)
{
	char		*temp;

	if ((f->sharp && (f->flag_5 == 'x' || f->flag_5 == 'X')) ||
		*(f->str) == '+' || *(f->str) == '-' || *(f->str) == ' ')
	{
		if (*(f->str) == '+' || *(f->str) == '-' || *(f->str) == ' ')
			fixer_helpers_helper(f, s);
		else
		{
			temp = f->str;
			f->str = ft_str_width(f->str + 2, '0', s - 2, "left, no");
			free(temp);
			if (f->flag_5 == 'X')
				f->str = ft_strjoin_free_2("0X", f->str);
			else
				f->str = ft_strjoin_free_2("0x", f->str);\
		}
	}
	else
		f->str = ft_str_width_free(f->str, '0', s, "left, no");
}

void			fixer(t_flag *f, int min, int null, int s)
{
	if (min && null)
		f->str = ft_str_width(f->str, '0', s, "right, no");
	else if (min && !(null))
		f->str = ft_str_width_free(f->str, ' ', s, "right, no");
	else if (null && !(min))
		fixer_helper(f, s);
	else
		f->str = ft_str_width_free(f->str, ' ', s, "left, no");
}
