/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixer_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:52:58 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 16:53:59 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	fixer_p(t_flag *f)
{
	char	*temp;

	if (f->before_dot > f->after_dot && !f->null)
	{
		if (f->min)
			f->str = ft_str_width_free(f->str, ' ', f->before_dot, "right, no");
		else
			f->str = ft_str_width_free(f->str, ' ', f->before_dot, "left, no");
	}
	else
	{
		temp = f->str;
		f->str = ft_str_width(f->str + 2, '0', f->after_dot, "left, no");
		free(temp);
		f->str = ft_strjoin_free_2("0x", f->str);
	}
}
