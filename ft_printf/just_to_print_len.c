/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_to_print_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:02:06 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:03:31 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	just_to_print_len(char *str, int *persent_indicate, t_list **lst)
{
	char * temp;
	size_t i;
	int c;

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
//		ft_putstr("1");
		i++;
		c = i;
		// while (str[c] == ' ' || str[c] == '0' || str[c] == '-' || str[c] == '+' ||
		// str[c] == '#' || str[c] == 'l' || str[c] == 'L' || str[c] == 'h' ||
		// str[c] == '*' || str[c] == '.' || str[c] == 'j' || str[c] == 'z' ||
		// (str[c] >= '0' && str[c] <= '9'))
		// {
		// 	if ((str[c] >= 'A' || str[c] <= 'Z') && !flag_end(str[c]))
		// 		{
		// 			*persent_indicate = -1;
		// 			return (c);
		// 		}
		// 	c++;
		// }
//		ft_putstr(&str[i]);
		if (is_it_flag(&str[i]) > 0 || flag_end(str[i]))
		{
//			ft_putstr("2");
			ft_lstadd(lst, ft_lstnew_without_copy((temp = ft_strdup_n(str, i - 1)), i - 1));
			*persent_indicate = 1;
			if (i)
				return (i - 1);
	//		ft_putstr("3");
			return (0);
		}
		else
		{
			//ft_putstr("4");

			ft_lstadd(lst, ft_lstnew_without_copy((temp = ft_strdup_n(str, i - 1)), i - 1));
			//ft_putstr(lst->content);
			i -= is_it_flag(&str[i]);
			*persent_indicate = -1;
		}
	}
	else
		*persent_indicate = 0;
	return (i);
}
