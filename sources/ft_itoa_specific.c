/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_specific.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 21:11:52 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/18 23:35:00 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static char		*return_so_big(char *int_p, size_t accuracy)
{
	char		*temp_1;
	char		*temp_2;

	temp_1 = ft_strjoin_free_1(int_p, ".");
	temp_2 = ft_strnew_filler(accuracy, '0');
	return (ft_strjoin_fr_both(temp_1, temp_2));
}

char			*ft_itoa_specific(long double num, size_t accuracy)
{
	t_double	fl;
	char		*result;
	char		*int_p;
	char		*float_p;

	fl.d = num;
	fl.s_parts.exponent -= 16382;
	if (!accuracy)
		return (integer_part(fl.s_parts.mantisa, fl.s_parts.exponent));
	int_p = integer_part(fl.s_parts.mantisa, fl.s_parts.exponent);
	if (fl.s_parts.exponent >= 64)
		return (return_so_big(int_p, accuracy));
	int_p = ft_strjoin_free_1(int_p, ".");
	float_p = float_part(fl.s_parts.mantisa, fl.s_parts.exponent);
	result = ft_strjoin_fr_both(int_p, float_p);
	result = ft_round(result, accuracy);
	if (fl.s_parts.sign)
		result = ft_strjoin_free_2("-", result);
	return (result);
}
