/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:58:31 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 16:59:55 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	fixer(t_flag *flag, int min, int null, int s)
{
	char	a;
	char	*temp;

	if (min && null)
		flag->str = ft_str_width(flag->str, '0', s, "right, no");
	else if (min && !(null))
		flag->str = ft_str_width_free(flag->str, ' ', s, "right, no");
	else if (null && !(min))
	{
		if ((flag->sharp && (flag->flag_5 == 'x' || flag->flag_5 == 'X')) ||
			*(flag->str) == '+' || *(flag->str) == '-' || *(flag->str) == ' ')
		{
			if (*(flag->str) == '+' || *(flag->str) == '-' || *(flag->str) == ' ')
			{
				a = *(flag->str);
				temp = flag->str;
				flag->str = ft_str_width(flag->str + 1, '0', s - 1, "left, no");
				free(temp);
				flag->str = ft_strjoin_fr_both(ft_strdup_n(&a, 1), flag->str);
			}
			else
			{
				temp = flag->str;
				flag->str = ft_str_width(flag->str + 2, '0', s - 2, "left, no");
				free(temp);
				if (flag->flag_5 == 'X')
					flag->str = ft_strjoin_free_2("0X", flag->str);
				else
					flag->str = ft_strjoin_free_2("0x", flag->str);
			}
		}
		else
			flag->str = ft_str_width_free(flag->str, '0', s, "left, no");
	}
	else
		flag->str = ft_str_width_free(flag->str, ' ', s, "left, no");
}
