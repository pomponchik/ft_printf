/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_specific_part_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:40:47 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/08 14:27:21 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char		*float_part(unsigned long int mantisa, unsigned int num_bits)
{
	char	*listing;
	size_t	index;
	char	*result;
	t_list	*lst;
	int		kk;

	if (!(listing = ft_bits_listing(&mantisa, sizeof(unsigned long int))))
		return (NULL);
	if (!(result = ft_strdup("0")))
		return (ft_free(listing));
	index = num_bits;
	lst = NULL;
	kk = 1;
	ft_str_reverse(listing);
	while (listing[index])
	{
		if (listing[index] == '1')
			ft_lstadd(&lst, ft_lstnew_no_copy(two_five(kk), kk + 1));
		kk++;
		index++;
	}
	free(listing);
	return (itoa_alignment(lst));
}

char		one_num_from_multi(char *num, size_t *ind_in)
{
	size_t	ind_out;

	*ind_in = 0;
	if (!*(num + 1))
	{
		*ind_in = 0;
		return (*num);
	}
	if (one_num_from_multi(ft_jump(num, 1), &ind_out) + ind_out >= '5')
	{
		if (*num < '9')
		{
			*num += 1;
			*ind_in = 0;
		}
		else
			*ind_in = 1;
	}
	return (*num);
}

size_t		out_round(char *num, size_t accuracy)
{
	size_t	ind;

	ind = 1;
	while (accuracy)
	{
		if (num[accuracy - 1] == '9')
			num[accuracy - 1] = '0';
		else
		{
			num[accuracy - 1]++;
			ind = 0;
			break ;
		}
		accuracy--;
	}
	if (ind)
		return (1);
	return (0);
}

char		*ft_round(char *num, size_t accuracy)
{
	char	*temp;
	size_t	indicate;
	size_t	size;

	if (ft_strlen(ft_strchr(num, '.') + 1) < accuracy)
		num = ft_strjoin_fr_both(num, ft_strnew_filler(accuracy - \
		ft_strlen(ft_strchr(num, '.') + 1), '0'));
	temp = ft_strchr(num, '.') + 1;
	one_num_from_multi(temp + accuracy, &indicate);
	temp[accuracy] = '\0';
	if (indicate)
		indicate = out_round(temp, accuracy);
	if (indicate)
	{
		size = ft_strchr(num, '.') - num;
		num = ft_math_longar_str_add_free_1(ft_strdup_n_free(num, size), "1");
		num = ft_strjoin_free_1(ft_math_longar_str_add_free_1(num, "1"), ".");
		num = ft_strjoin_fr_both(num, ft_strnew_filler(accuracy, '0'));
		return (num);
	}
	return (ft_strdup_free(num));
}

char		*ft_itoa_accuracy(t_double *fl)
{
	char	*result;

	result = integer_part(fl->s_parts.mantisa, fl->s_parts.exponent);
	*((char *)(ft_strchr(result, '.'))) = '\0';
	return (result);
}
