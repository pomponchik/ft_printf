/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_to_print_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:02:06 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/15 18:47:06 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	just_to_print_len(char *str, int *persent_indicate, t_list **lst)
{
	char	*temp;
	size_t	i;

	i = 0;
	*persent_indicate = 0;
	if (!str[i])
	{
		*persent_indicate = 0;
		return (0);
	}
	while (str[i] && str[i] != '%')
		i++;
	if (str[i] == '%')
	{
		i++;
		if (is_it_flag(&str[i]) > 0 || flag_end(str[i]))
		{
			ft_lstadd(lst, ft_lstnew_without_copy((temp = ft_strdup_n(str, i - 1)), i - 1));
			*persent_indicate = 1;
			if (i)
				return (i - 1);
			return (0);
		}
		else
		{
			ft_lstadd(lst, ft_lstnew_without_copy((temp = ft_strdup_n(str, i - 1)), i - 1));
			i -= is_it_flag(&str[i]);
			*persent_indicate = -1;
		}
	}
	else
		*persent_indicate = 0;
	return (i);
}
