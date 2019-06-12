/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:09:59 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/22 15:41:36 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base_long(t_flag *flag, uintmax_t value, int base)
{
	char	*str;
	int		size;
	char	*tab;
	int		f;
	uintmax_t		tmp;

	if (!value)
		return (ft_strnew_filler(1, '0'));
	f = 0;
	size = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	if (flag->hh)
			value = (unsigned char)value;
	if (flag->h)
			value = (unsigned short)value;
	if (flag->l || flag->flag_5 == 'O')
			value = (unsigned long)value;
	if (flag->ll)
		value = (unsigned long long)value;
	if (flag->flag_5 != 'O' && !flag->hh && !flag->h && !flag->l && !flag->ll)
			value = (unsigned int)value;
	if (base == 10)
			f = 1;
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + f + 1;
	str = (char *)malloc(sizeof(char) * size  + 1);
	str[size] = '\0';
	if (f == 1)
		str[0] = '-';
	while (size > f)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /=base;
	}
	return (str);
}
