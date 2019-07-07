/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_flag_before.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:07:19 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 18:56:26 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	first_flag_before_helper(long long int i, t_flag *flag)
{
	if (flag->dot && i == 0 && (flag->flag_5 == 'd' || flag->flag_5 == 'i' ||
		flag->flag_5 == 'u' || flag->flag_5 == 'o' ||
		flag->flag_5 == 'x' || flag->flag_5 == 'X'))
		flag->str = ft_strdup("");
	if ((flag->flag_5 == 'o' || flag->flag_5 == 'O') && flag->sharp)
		flag->str = ft_strjoin_free_2("0", flag->str);
	else if (flag->sharp && (flag->flag_5 == 'x' || flag->flag_5 == 'X'))
	{
		if (flag->flag_5 == 'X')
			flag->str = ft_strjoin_free_2("0X", flag->str);
		else
			flag->str = ft_strjoin_free_2("0x", flag->str);
	}
}

void		first_flag_before(long long int i, t_flag *flag)
{
	if (flag->dot && flag->after_dot == 0 && flag->flag_5 == 's')
		flag->str = ft_strdup("");
	if (flag->flag_5 == 'p' && flag->null)
		flag->min = 1;
	if ((i == 0 && flag->dot) || (flag->sharp && flag->flag_5 == 'd'))
		flag->null = 0;
	if (flag->plus && i >= 0 && !(flag->flag_5 == 's' || flag->flag_5 == 'o' ||
		flag->flag_5 == 'O'))
		flag->str = ft_strjoin_free_2("+", flag->str);
	else if (flag->space && (flag->flag_5 == 'd' || flag->flag_5 == 'i') &&
	(*(flag->str) != '+' || *(flag->str) != '-') && i >= 0)
		flag->str = ft_strjoin_free_2(" ", flag->str);
	if (flag->sharp && !ft_strcmp(flag->str, "0") &&
	!(flag->dot && flag->flag_5 == 'o'))
		flag->sharp = 0;
	first_flag_before_helper(i, flag);
}
