/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixer_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:54:58 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 17:54:20 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	fixer_str(t_flag *f, size_t *l)
{
	int	len;

	if (!f->ind_c)
		len = ft_strlen(f->str);
	else
	{
		charer(f, l);
		return ;
	}
	if (f->after_dot && f->after_dot < len)
	{
		f->str = ft_str_width(f->str, ' ', f->after_dot, "crop: end");
		len = f->after_dot;
	}
	if (len < f->before_dot)
	{
		if (f->min)
			f->str = ft_str_width(f->str, ' ', f->before_dot, "right, no");
		else if (f->null)
			f->str = ft_str_width(f->str, '0', f->before_dot, "left, no");
		else
			f->str = ft_str_width(f->str, ' ', f->before_dot, "left, no");
	}
}
