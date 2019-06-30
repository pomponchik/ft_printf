/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:09:59 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 19:31:21 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static void		ft_itoa_base_long_nuller(int *size, int *f, \
	uintmax_t *tmp, uintmax_t value)
{
	*f = 0;
	*size = 0;
	*tmp = value;
}

static int		ft_itoa_base_long_defender(int base, int *f)
{
	int			result;

	result = 1;
	if (base == 10)
		*f = 1;
	else if (base < 2 || base > 16)
		result = 0;
	return (result);
}

static int		ft_itoa_base_long_resize(uintmax_t *tmp, int size, \
	int *f, int base)
{
	while (*tmp /= base)
		size++;
	return (size + *f + 1);
}

char			*ft_itoa_base_long(uintmax_t value, int base)
{
	char		*str;
	int			size;
	char		*tab;
	int			f;
	uintmax_t	tmp;

	if (!value)
		return (ft_strnew_filler(1, '0'));
	ft_itoa_base_long_nuller(&size, &f, &tmp, value);
	tab = "0123456789ABCDEF";
	if (!ft_itoa_base_long_defender(base, &f))
		return (NULL);
	size = ft_itoa_base_long_resize(&tmp, size, &f, base);
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	if (f == 1)
		str[0] = '-';
	while (size > f)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (str);
}
