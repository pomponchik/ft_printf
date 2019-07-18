/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_specific_part_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:43:37 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/30 17:11:46 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*integer_part(unsigned long int mantisa, unsigned int num_bits)
{
	char	*listing;
	size_t	index;
	char	*result;

	if (!(listing = ft_bits_listing(&mantisa, sizeof(unsigned long int))))
		return (NULL);
	ft_str_reverse(listing);
	if (!num_bits || num_bits == 32766)
		return (ft_strdup("0"));
	if (!(result = ft_strdup("0")))
		return (ft_free(listing));
	index = 0;
	while (listing[index] && num_bits)
	{
		if (listing[index] == '1')
			result = ft_math_longar_str_add_free_both(result,
		ft_math_longar_str_exponent_mix("2", (unsigned long int)num_bits - 1));
		num_bits--;
		index++;
	}
	free(listing);
	return (result);
}

char	*two_five(size_t two)
{
	char	*result;
	char	*t;
	char	*f;
	size_t	size;

	t = ft_math_longar_str_exponent_mix("2", (unsigned long int)two);
	f = ft_math_longar_str_exponent_mix("5", (unsigned long int)two);
	t = ft_math_longar_str_multi_free_1(t, f);
	if (!(size = ft_strlen_safe(t)))
		return (ft_free_both(t, f));
	if (!(two = ft_strlen_safe(f)))
		return (ft_free_both(t, f));
	size--;
	if (two != size)
	{
		result = ft_strjoin_fr_both(ft_strnew_filler(size - two, '0'), f);
		return (result);
	}
	return (f);
}

char	*itoa_adder(t_list *lst)
{
	char	*result;
	t_list	*temp;
	char	*res_2;

	temp = lst;
	if (!(result = ft_strdup("0")))
	{
		ft_lst_free_chain(lst);
		return (NULL);
	}
	while (lst)
	{
		if (lst->content)
		{
			result = ft_math_longar_str_add_free_1(result, lst->content);
			result[0] = '1';
		}
		lst = lst->next;
	}
	res_2 = ft_strdup(ft_jump(result, 1));
	free(result);
	return (res_2);
}

size_t	max_sizes(t_list *lst)
{
	size_t	result;

	result = 0;
	while (lst)
	{
		if (lst->content_size > result)
			result = lst->content_size;
		lst = lst->next;
	}
	return (result);
}

char	*itoa_alignment(t_list *lst)
{
	t_list	*temp;
	size_t	max_size;
	size_t	this_size;

	if (!lst)
		return (ft_strdup("0"));
	temp = lst;
	max_size = max_sizes(lst);
	while (lst)
	{
		if (lst->content)
		{
			this_size = ft_strlen(lst->content);
			if (this_size != max_size)
			{
				lst->content = ft_strjoin_fr_both(lst->content, \
				ft_strnew_filler(max_size - this_size, '0'));
				lst->content = ft_strjoin_free_2("1", lst->content);
			}
		}
		lst = lst->next;
	}
	return (itoa_adder(temp));
}
