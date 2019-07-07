/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:51:10 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 17:38:06 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	charer(t_flag *flag, size_t *len)
{
	char	*temp;
	char	*str;

	if (flag->before_dot)
	{
		if (flag->null)
			str = ft_strnew_filler(flag->before_dot - 1, '0');
		else
			str = ft_strnew_filler(flag->before_dot - 1, ' ');
		*len = flag->before_dot;
		temp = flag->str;
		if (!flag->min)
			flag->str = (char *)ft_memjoin(str, flag->before_dot - 1,
						flag->str, 1);
		else
			flag->str = (char *)ft_memjoin(flag->str, 1, str,
						flag->before_dot - 1);
		ft_free_both(temp, str);
	}
	else
		*len = 1;
}
