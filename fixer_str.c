/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixer_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:54:58 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 16:55:55 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	fixer_str(t_flag *flag, size_t *l)
{
	int	len;

	if (!flag->ind_c)
		len = ft_strlen(flag->str);
	else
	{
		charer(flag, l);
		return ;
	}
	if (flag->after_dot && flag->after_dot < len)
	{
		flag->str = ft_str_width(flag->str, ' ', flag->after_dot, "crop: end");
		len = flag->after_dot;
	}
	if (len < flag->before_dot)
	{
		if (flag->min)
			flag->str = ft_str_width(flag->str, ' ', flag->before_dot, "right, no");
		else if (flag->null)
			flag->str = ft_str_width(flag->str, '0', flag->before_dot, "left, no");
		else
			flag->str = ft_str_width(flag->str, ' ', flag->before_dot, "left, no");
	}
}
