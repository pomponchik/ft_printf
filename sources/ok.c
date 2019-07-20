/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:53:24 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/29 20:18:17 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	ok(char *str, t_flag *flag)
{
	size_t	num;
	size_t	temp;

	num = 0;
	while (!flag_end(&str[num]))
	{
		temp = 0;
		if (flag_begin_chek(&str[num + temp], flag))
			temp += flag_begin_chek(&str[num + temp], flag);
		if (str[num + temp] == '.')
		{
			flag->dot = 1;
			flag->after_flag = 1;
			if (str[num + temp + 1] >= '0' && str[num + temp + 1] <= '9')
			{
				flag->after_dot = ft_atoi(str + num + temp + 1);
				temp += ft_math_numlen_long((long int)flag->after_dot) + 1;
			}
		}
		else if (!flag->dot && second_flag(&str[num + temp], flag))
			temp += ft_math_numlen_long((long int)flag->before_dot);
		temp += size_flag(&str[num + temp], flag, temp);
		num += temp;
	}
	return (num);
}
