/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_specific.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 21:11:52 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 16:38:45 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*ft_itoa_specific(long double num, size_t accuracy)
{
	t_double	fl;
	char		*result;

	fl.d = num;
	fl.s_parts.exponent -= 16382;
	if (!accuracy)
		return (ft_itoa_accuracy(&fl));
	if (fl.s_parts.exponent < 64)
		result = ft_strjoin_fr_both(integer_part(fl.s_parts.mantisa,
		fl.s_parts.exponent), float_part(fl.s_parts.mantisa,
		fl.s_parts.exponent));
	else
	{
		result = ft_strjoin_free_1(integer_part(fl.s_parts.mantisa,
												fl.s_parts.exponent), ".");
		result = ft_strjoin_fr_both(result, ft_strnew_filler(accuracy, '0'));
	}
	result = ft_round(result, accuracy);
	if (fl.s_parts.sign)
		result = ft_strjoin_free_2("-", result);
	return (result);
}
