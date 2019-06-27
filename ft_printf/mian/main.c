/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:09:28 by kbethany          #+#    #+#             */
/*   Updated: 2019/05/04 15:20:33 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../head.h"

char *integer_part(unsigned long int mantisa, unsigned int num_bits)
{
	char *listing;
	size_t index;
	char *result;

	if (!(listing = ft_bits_listing(&mantisa, sizeof(unsigned long int))))
		return (NULL);
	if (!(result = ft_strdup("0")))
		return (ft_free(listing));
	index = 0;
	ft_str_reverse(listing);
	while (listing[index] && num_bits)
	{
		if (listing[index] == '1')
			result = ft_math_longar_str_add_free_both(result, \
				ft_math_longar_str_exponent_mix("2", (unsigned long int)num_bits - 1));
		num_bits--;
		index++;
	}
	free(listing);
	return (ft_strjoin_free_1(result, "."));
}

char *two_five(size_t two)
{
	char *result;
	char *t;
	char *f;
	size_t size;

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

char *itoa_adder(t_list *lst)
{
	char *result;
	t_list *temp;
	char *res_2;

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

size_t max_sizes(t_list *lst)
{
	size_t result;

	result = 0;
	while (lst)
	{
		if (lst->content_size > result)
			result = lst->content_size;
		lst = lst->next;
	}
	return (result);
}

char *itoa_alignment(t_list *lst)
{
	t_list *temp;
	size_t max_size;
	size_t this_size;

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

char *float_part(unsigned long int mantisa, unsigned int num_bits)
{
	char *listing;
	size_t index;
	char *result;
	t_list *lst;
	int kk;

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
			ft_lstadd(&lst, ft_lstnew_without_copy(two_five(kk), kk + 1));
		kk++;
		index++;
	}
	free(listing);
	return (itoa_alignment(lst));
}

int				one_num_from_multi(char *num, size_t *ind_in)
{
	size_t				ind_out;

	if (!*(num + 1))
	{
		printf("if 1, if 1, sign: %c\n", *num);
		*ind_in = 0;
		return ((int)(num - '0'));
	}
	if (one_num_from_multi(num + 1, &ind_out) + ind_out >= 5)
	{
		*ind_in = 1;
		printf("if 2, sign: %c, ind: %lu\n", *num, ind_out);
		return (0);
		// if (*num - '0' + ind_out <= 9)
		// {
		// 	printf("if 2, if 1, sign: %c, ind: %lu\n", *num, ind_out);
		// 	printf("%lu\n", *num - '0' + ind_out);
		// 	*ind_in = 0;
		// 	return (0);
		// }
		// else
		// {
		// 	printf("if 2, if 2, sign: %c\n", *num);
		// 	*ind_in = 1;
		// 	return ((*num - '0' + ind_out) - 10);
		// }
	}
	*ind_in = 0;
	printf("return, sign: %c\n", *num);
	return ((int)*num - '0' + ind_out);
}

char *ft_round(char *num, size_t accuracy)
{
	char *temp;
	size_t i;
	size_t size;

	temp = ft_strchr(num, '.') + 1;
	ft_putstr(temp);
	ft_putstr("\n");
	temp[accuracy - 1] = (char)one_num_from_multi(num + accuracy - 1, &i) + i + '0';
	temp[accuracy] = '\0';
	if (i)
	{
		printf("jj\n");
		while (accuracy)
		{
			if (temp[accuracy - 1] - '0' + i > 9)
				temp[accuracy - 1] = '0';
			else
			{
				temp[accuracy - 1] = temp[accuracy - 1] + 1;
				i = 0;
				break ;
			}
			accuracy--;
		}
		if (i)
			return (ft_strdup_n_free(num, ft_strlen(num) - (temp - num)));
	}
	return (ft_strdup_free(num));
}

char *ft_itoa_specific(long double num, size_t accuracy)
{
	t_double fl;
	char *result;

	fl.d = num;
	fl.s_parts.exponent -= 16382;
	if (!(result = ft_strjoin_fr_both(integer_part(fl.s_parts.mantisa, \
		fl.s_parts.exponent), float_part(fl.s_parts.mantisa, \
			fl.s_parts.exponent))))
		return (NULL);
	if (fl.s_parts.sign)
		result = ft_strjoin_free_2("-", result);
	result = ft_round(result, accuracy);
	return (result);
}

int	main()
{
	//printf("%s\n", res(1.875 ));
	printf("%s\n", ft_itoa_specific(1.65, 6));
	//printf("%s\n", ft_itoa_long_double_old(1.65, 6));

	printf("%f\n", 1.66);
	return (0);
}
