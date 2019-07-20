/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_nuller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:51:32 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 17:57:28 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	flag_nuller(t_flag *flag)
{
	flag->lst = NULL;
	flag->null = 0;
	flag->min = 0;
	flag->sharp = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->dot = 0;
	flag->before_dot = 0;
	flag->after_dot = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->flag_5 = 0;
	flag->before_flag = 0;
	flag->after_flag = 0;
	flag->str = NULL;
	flag->i = 0;
	flag->ind_c = 0;
	(flag->file).size = 0;
	(flag->file).mem = NULL;
}
