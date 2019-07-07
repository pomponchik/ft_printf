/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:24:08 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:18:51 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	second_flag(char *a, t_flag *flag)
{
	if (ft_isdigit(*a))
	{
		flag->before_flag = 1;
		flag->before_dot = ft_atoi(a);
		return (ft_math_numlen_long((long int)flag->before_dot));
	}
	return (0);
}
