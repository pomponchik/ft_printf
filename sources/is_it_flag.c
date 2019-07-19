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

int	flag_end(char *s)
{
	if (ft_strnstr(s, "list", 4) || ft_strnstr(s, "file", 4) ||
	ft_strnstr(s, "dlist", 5))
		return (1);
	if (*s == 'c' || *s == 'f' || *s == 'd' || *s == 's' || *s == 'i' ||
		*s == 'o' || *s == 'u' || *s == 'x' || *s == 'X' || *s == 'p' ||
		*s == 'b' || *s == '%' || *s == 'U' || *s == 'D' || *s == 'O' ||
		*s == 'F' || *s == 'g')
		return (1);
	return (0);
}

int	is_it_flag(char *str)
{
	int i;

	i = 0;
	if (ft_strnstr(str, "list", 4) || ft_strnstr(str, "file", 4))
		return (4);
	if (ft_strnstr(str, "dlist", 5))
		return (5);
	while (str[i] == ' ' || str[i] == '0' || str[i] == '-' || str[i] == '+' ||
	str[i] == '#' || str[i] == 'l' || str[i] == 'L' || str[i] == 'h' ||
	str[i] == '.' || str[i] == 'j' || str[i] == 'z' ||
	(str[i] >= '0' && str[i] <= '9'))
		i++;
	if (flag_end(&str[i]))
		return (i);
	return (-i);
}
