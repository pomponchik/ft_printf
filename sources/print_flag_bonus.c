/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:33:34 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/20 16:36:14 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	print_flag_bonus_helper(t_flag *flag, va_list *arguments)
{
	void		*binary;
	t_list		*list;
	size_t		size;
	char		*result;

	if (flag->flag_5 == 'e')
	{
		list = va_arg(*arguments, t_list *);
		result = lst_print_deduplication(list);
		size = ft_strlen(result);
		ft_lstadd(&(flag->lst), ft_lstnew_no_copy(result, size));
		return (size);
	}
	binary = va_arg(*arguments, void *);
	size = va_arg(*arguments, size_t);
	result = ft_bits_listing(binary, size);
	size = ft_strlen_safe(result);
	ft_lstadd(&(flag->lst), ft_lstnew_no_copy(result, size));
	return (size);
}

size_t	print_flag_bonus(t_flag *flag, va_list *arguments)
{
	char		*file_name;
	size_t		size;
	t_list		*list;
	char		*str;

	if (flag->flag_5 == 'y')
	{
		file_name = va_arg(*arguments, char *);
		ft_lstadd(&(flag->lst),\
		ft_lstnew_no_copy(ft_get_file(file_name, &size), size));
		return (size);
	}
	if (flag->flag_5 == 'q')
	{
		list = va_arg(*arguments, t_list *);
		str = lst_print_cs(list);
		size = ft_strlen(str);
		ft_lstadd(&(flag->lst), ft_lstnew_no_copy(str, size));
		return (size);
	}
	return (print_flag_bonus_helper(flag, arguments));
}
