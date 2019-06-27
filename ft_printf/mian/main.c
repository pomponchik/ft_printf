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

typedef struct			s_num
{
	char *number;
	char *up;
	int exp;
}						t_num;



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
//
// char *fdcv(t_list *lst)
// {
// 	char *five;
// 	int ex;
// 	t_num *pa;
// 	char *temp;
// 	int index = 0;
// 	t_list *ls;
// 	t_list *l;
// 	char *result = ft_strdup("0");
//
// 	pa = lst->content;
// 	ex = pa->exp;
// 	temp = pa->number;
// 	pa->up = ft_strdup("1");
// 	char *mem = ft_strdup(pa->number);
// 	if (!(five = ft_math_longar_str_exponent_mix("5", ex)))
// 		return (NULL);
// 	ls = lst->next;
// 	while (ls)
// 	{
// 		pa = ls->content;
// 		pa->up = pa->number;
// 		pa->number = ft_math_longar_str_multi_free_1(ft_math_longar_str_exponent_mix("2", index), pa->number);
// 		ls = ls->next;
// 		index++;
// 	}
// 	l = lst;
// 	while (l)
// 	{
// 		pa = l->content;
// 		l = l->next;
// 		result = ft_math_longar_str_add_free_1(result, pa->up);
// 	}
// 	result = ft_math_longar_str_multi_free_1(result, five);
// 	result = ft_str_fix_width_of_line_free(result, '0', ft_strlen(ft_math_longar_str_multi(mem, five)) - 1, "alignment: left, crop: no");
// 	return (result);
// }

char *gg(t_list *lst)
{
	t_list *temp;
	char *result;
	char *temp_res;
	size_t index = 0;
	temp = lst;
	result = NULL;
	ft_lst_putstr_sep(lst, ", ");
	ft_putchar('\n');
	while (lst)
	{
		if (lst->next)
		{
			result = ft_math_longar_str_add(lst->content, (lst->next)->content);
			result[0] = '1';
		}
		index++;
		lst = lst->next;
	}
	if (!index)
		result = ft_strdup(lst->content);
	ft_lst_free_chain(temp);
	temp_res = ft_strdup(ft_jump(result, 1));
	free(result);
	ft_putstr("ahah\n");
	return (temp_res);
}

char *yy(t_list *lst, size_t size)
{
	t_list *temp;

	temp = lst;
	ft_lst_putstr_sep(lst, ", ");
	ft_putchar('\n');
	while (lst)
	{
		// if (ft_strlen(lst->content) != size)
		// {
		// 	lst->content = ft_strjoin_fr_both(ft_strnew_filler(size - ft_strlen(lst->content), '0'), lst->content);
		// }
		lst->content = ft_str_fix_width_of_line_free(lst->content, '0', size, "alignment: right, crop: no");
		lst->content = ft_strjoin_free_2("1", lst->content);
		lst = lst->next;
	}
	ft_putstr("ohoh\n");
	return (gg(temp));
}

char *f(t_list *lst)
{
	char *five;
	size_t len;
	t_list *temp;

	if (!lst)
		return (ft_strdup("0"));
	if (!(five = ft_math_longar_str_exponent_mix("2", lst->content_size + 1)))
	{
		ft_lst_free_chain(lst);
		return (NULL);
	}
	if (!(five = ft_math_longar_str_multi_free_1(five, lst->content)))
	{
		ft_lst_free_chain(lst);
		return (NULL);
	}
	temp = lst;
	len = ft_strlen(five) - 1;
	ft_putstr("vot = ");
	ft_putnbr((int)len);
	ft_putchar('\n');
	free(five);
	ft_lst_putstr_sep(lst, ", ");
	ft_putchar('\n');
	while (lst)
	{
		if (!(five = ft_math_longar_str_exponent_mix("5", lst->content_size - 1)))
		{
			ft_lst_free_chain(temp);
			return (NULL);
		}
		lst->content = ft_math_longar_str_multi_free_both(lst->content, five);
		lst = lst->next;
	}
	ft_putstr("haha\n");
	return (yy(temp, len));
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
	ft_putstr(&listing[index]);
		ft_putstr("\n");
	while (listing[index])
	{
		if (listing[index] == '1')
			ft_lstadd(&lst, ft_lstnew_without_copy(ft_math_longar_str_exponent_mix("5", (unsigned long int)kk), kk + 1 ));
		kk++;
		index++;
	}
	free(listing);
	ft_putstr("hehe\n");
	return (f(lst));
}

char *res(long double num)
{
	t_double fl;

	fl.d = num;
	fl.s_parts.exponent -= 16382;
	unsigned long int j = fl.s_parts.mantisa;
	char *result = ft_strjoin(integer_part(fl.s_parts.mantisa, fl.s_parts.exponent), float_part(fl.s_parts.mantisa, fl.s_parts.exponent));
	ft_putstr("gogo\n");
	if (fl.s_parts.sign)
		result = ft_strjoin_free_2("-", result);
	return (result);
}

int	main()
{
	//printf("%s\n", res(1.875 ));
	printf("%s\n", res(1.9375));
	printf("%f\n", 1.9375);
	return (0);
}
