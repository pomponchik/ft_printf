/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:41:15 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 18:41:47 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	shorter(char *a, t_flag *flag)
{
	if (*a == 'h')
	{
		if (*(a + 1) == 'h')
		{
			flag->hh++;
			return (2);
		}
		else
			flag->h++;
		return (1);
	}
	return (0);
}

int			size_flag(char *a, t_flag *flag, size_t s)
{
	if (flag->flag_5 == 0 && flag->l == 0 && flag->ll == 0 &&
		flag->hh == 0 && flag->h == 0)
	{
		if (*a == 'j' || *a == 'z' || *a == 'L')
		{
			flag->ll++;
			return (1);
		}
		else if (*a == 'l')
		{
			if (*(a + 1) == 'l')
			{
				flag->ll++;
				return (2);
			}
			else
				flag->l++;
			return (1);
		}
		else if (shorter(a, flag))
			return (shorter(a, flag));
	}
	if (!s)
		return (1);
	return (0);
}
