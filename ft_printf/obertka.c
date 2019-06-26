/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obertka.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:56:32 by kbethany          #+#    #+#             */
/*   Updated: 2019/06/19 20:00:57 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	charer(t_flag *flag, size_t *len)
{
	char	*temp;
	char	*str;

	if (flag->before_dot)
	{
		if (flag->null)
			str = ft_strnew_filler(flag->before_dot - 1, '0');
		else
			str = ft_strnew_filler(flag->before_dot - 1, ' ');
		*len = flag->before_dot;
		temp = flag->str;
		if (!flag->min)
			flag->str = (char *)ft_memjoin(str, flag->before_dot - 1, flag->str, 1);
		else
			flag->str = (char *)ft_memjoin(flag->str, 1, str, flag->before_dot - 1);
		ft_free_both(temp, str);
	}
	else
		*len = 1;
}

void fixer_p(t_flag *flag)
{
	if (flag->before_dot > flag->after_dot && !flag->null)
	{
		if (flag->min)
			flag->str = ft_str_fix_width_of_line(flag->str, ' ', flag->before_dot, "alignment: right, crop: no");
		else
			flag->str = ft_str_fix_width_of_line(flag->str, ' ', flag->before_dot, "alignment: left, crop: no");
	}
	else
	{
		flag->str = ft_str_fix_width_of_line(flag->str + 2, '0', flag->after_dot, "alignment: left, crop: no");
		flag->str = ft_strjoin_free_2("0x", flag->str);
	}
}

void	fixer_str(t_flag *flag, size_t *l)
{
	int	len;

	if (!flag->ind_c)
		len = ft_strlen(flag->str);
	else
	{
		charer(flag, l);
		return ;
	}
	if (flag->after_dot && flag->after_dot < len)
	{
		flag->str = ft_str_fix_width_of_line(flag->str, ' ', flag->after_dot, "crop: end");
		len = flag->after_dot;
	}
	if (len < flag->before_dot)
	{
		if (flag->min)
			flag->str = ft_str_fix_width_of_line(flag->str, ' ', flag->before_dot, "alignment: right, crop: no");
		else if (flag->null)
			flag->str = ft_str_fix_width_of_line(flag->str, '0', flag->before_dot, "alignment: left, crop: no");
		else
			flag->str = ft_str_fix_width_of_line(flag->str, ' ', flag->before_dot, "alignment: left, crop: no");
	}
}

void	fixer_free(t_flag *flag, int min, int null, int s)
{
	char	a;

	if (min && null)
	{
	//	ft_putnbr(6);
		flag->str = ft_str_fix_width_of_line_free(flag->str, '0', s, "alignment: right, crop: no");
	}
	else if (min && !(null))
	{
	//	ft_putnbr(7);
		flag->str = ft_str_fix_width_of_line_free(flag->str, ' ', s, "alignment: right, crop: no");
	}
	else if (null && !(min))
	{
//	ft_putnbr(8);
		if ((flag->sharp && (flag->flag_5 == 'x' || flag->flag_5 == 'X')) ||
			*(flag->str) == '+' || *(flag->str) == '-' || *(flag->str) == ' ')
		{
			if (*(flag->str) == '+' || *(flag->str) == '-' || *(flag->str) == ' ')
			{
				//	ft_putnbr(9);
				a = *(flag->str);
				flag->str = ft_str_fix_width_of_line_free(flag->str + 1, '0', s - 1, "alignment: left, crop: no");
				flag->str = ft_strjoin_free_1(ft_strdup_n(&a, 1), flag->str);
			}
			else
			{
			//		ft_putnbr(10);
				flag->str = ft_str_fix_width_of_line_free(flag->str + 2, '0', s - 2, "alignment: left, crop: no");
				if (flag->flag_5 == 'X')
					flag->str = ft_strjoin_free_2("0X", flag->str);
				else
					flag->str = ft_strjoin_free_2("0x", flag->str);
			}
		}
		else
		{
		//	ft_putnbr(11);
			flag->str = ft_str_fix_width_of_line_free(flag->str, '0', s, "alignment: left, crop: no");
		}
	}
	else
	{
	//		ft_putnbr(12);
		flag->str = ft_str_fix_width_of_line_free(flag->str, ' ', s, "alignment: left, crop: no");
	}
}

void	fixer(t_flag *flag, int min, int null, int s)
{
	char	a;

	if (min && null)
	{
	//	ft_putnbr(31);
		flag->str = ft_str_fix_width_of_line(flag->str, '0', s, "alignment: right, crop: no");
	}
	else if (min && !(null))
	{
	//	ft_putnbr(32);
		flag->str = ft_str_fix_width_of_line(flag->str, ' ', s, "alignment: right, crop: no");
	}
	else if (null && !(min))
	{
		if ((flag->sharp && (flag->flag_5 == 'x' || flag->flag_5 == 'X')) ||
			*(flag->str) == '+' || *(flag->str) == '-' || *(flag->str) == ' ')
		{
			if (*(flag->str) == '+' || *(flag->str) == '-' || *(flag->str) == ' ')
			{
		//		ft_putnbr(33);
				a = *(flag->str);
				flag->str = ft_str_fix_width_of_line(flag->str + 1, '0', s - 1, "alignment: left, crop: no");
				flag->str = ft_strjoin_free_1(ft_strdup_n(&a, 1), flag->str);
			}
			else
			{
		//		ft_putnbr(34);
				flag->str = ft_str_fix_width_of_line(flag->str + 2, '0', s - 2, "alignment: left, crop: no");
				if (flag->flag_5 == 'X')
					flag->str = ft_strjoin_free_2("0X", flag->str);
				else
					flag->str = ft_strjoin_free_2("0x", flag->str);
			}
		}
		else
		{
		//	ft_putnbr(35);
			flag->str = ft_str_fix_width_of_line(flag->str, '0', s, "alignment: left, crop: no");
		}
	}
	else
	{
	//	ft_putnbr(36);
		flag->str = ft_str_fix_width_of_line(flag->str, ' ', s, "alignment: left, crop: no");
	}
}

int	fixer_num(t_flag *flag)
{
	int	len;
	int	c;

	c = 0;
//	ft_putnbr(1);
	len = ft_strlen(flag->str);
	if (flag->space || flag->plus)
		len--;
	if (len >= flag->before_dot && len >= flag->after_dot)
		return (0);
	if (flag->flag_5 == '%' && flag->before_dot == 0)
	{
		flag->str = ft_strdup("%");
		return (0);
	}
	if (len >= flag->after_dot)
		flag->after_dot = 0;
	if(flag->after_dot)
	{
		if (flag->after_dot > flag->before_dot)
			flag->before_dot = 0;
		if (flag->flag_5 == 'd' || flag->flag_5 == 'i' || flag->flag_5 == 'o' ||
			flag->flag_5 == 'u' || flag->flag_5 == 'x' || flag->flag_5 == 'X')
		{
			if (*(flag->str) == '-' || *(flag->str) == '+' || *(flag->str) == ' ')
				flag->after_dot++;
			if ((flag->flag_5 == 'x' || flag->flag_5 == 'X') && len == 3)
					flag->after_dot += 2;
			fixer(flag, 0, 1, flag->after_dot);
			flag->null = 0;
			c++;
		}
		else
		{
	//		ft_putnbr(3);
		fixer(flag, flag->min, flag->null, flag->after_dot);
		}
	}
	if (c)
	{
		//ft_putnbr(4);
		fixer_free(flag, flag->min, flag->null, flag->before_dot);
	}
	else
	{
		//ft_putnbr(5);
		fixer(flag, flag->min, flag->null, flag->before_dot);
	}
	return (0);
}
