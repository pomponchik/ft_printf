/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:59:03 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/15 16:46:05 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	flag_end(char s)
{
	if (s == 'c' || s == 'f' || s == 'd' || s == 's' || s == 'i' || s == 'o' ||
		s == 'u' || s == 'x' || s == 'X' || s == 'p' || s == '%' || s == 'U' ||
		s == 'D' || s == 'O' || s == 'F')
		return (1);
	return (0);
}

int	is_it_flag(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '0' || str[i] == '-' || str[i] == '+' ||
	str[i] == '#' || str[i] == 'l' || str[i] == 'L' || str[i] == 'h' ||
	str[i] == '*' || str[i] == '.' || str[i] == 'j' || str[i] == 'z' ||
	(str[i] >= '0' && str[i] <= '9'))
		i++;
	if (flag_end(str[i]))
		return (i);
	return (-i);
}
