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

void fixer_p(t_flag *f)
{
	char	*temp;

	if (f->before_dot > f->after_dot && !f->null)
	{
		if (f->min)
			f->str = ft_str_width_free(f->str, ' ', f->before_dot, "right, no");
		else
			f->str = ft_str_width_free(f->str, ' ', f->before_dot, "left, no");
	}
	else
	{
		temp = f->str;
		f->str = ft_str_width(f->str + 2, '0', f->after_dot, "left, no");
		free(temp);
		f->str = ft_strjoin_free_2("0x", f->str);
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
		flag->str = ft_str_width(flag->str, ' ', flag->after_dot, "crop: end");
		len = flag->after_dot;
	}
	if (len < flag->before_dot)
	{
		if (flag->min)
			flag->str = ft_str_width(flag->str, ' ', flag->before_dot, "right, no");
		else if (flag->null)
			flag->str = ft_str_width(flag->str, '0', flag->before_dot, "left, no");
		else
			flag->str = ft_str_width(flag->str, ' ', flag->before_dot, "left, no");
	}
}

void	fixer_free(t_flag *flag, int min, int null, int s)
{
	char	a;
	char *temp;

	if (min && null)
		flag->str = ft_str_width_free(flag->str, '0', s, "right, no");
	else if (min && !(null))
		flag->str = ft_str_width_free(flag->str, ' ', s, "right, no");
	else if (null && !(min))
	{
		if ((flag->sharp && (flag->flag_5 == 'x' || flag->flag_5 == 'X')) ||
			*(flag->str) == '+' || *(flag->str) == '-' || *(flag->str) == ' ')
		{
			if (*(flag->str) == '+' || *(flag->str) == '-' || *(flag->str) == ' ')
			{
				a = *(flag->str);
				temp = flag->str;
				flag->str = ft_str_width_free(flag->str + 1, '0', s - 1, "left, no");
				free(temp);
				flag->str = ft_strjoin_free_1(ft_strdup_n(&a, 1), flag->str);
			}
			else
			{
				temp = flag->str;
				flag->str = ft_str_width_free(flag->str + 2, '0', s - 2, "left, no");
				free(temp);
				if (flag->flag_5 == 'X')
					flag->str = ft_strjoin_free_2("0X", flag->str);
				else
					flag->str = ft_strjoin_free_2("0x", flag->str);
			}
		}
		else
			flag->str = ft_str_width_free(flag->str, '0', s, "left, no");
	}
	else
		flag->str = ft_str_width_free(flag->str, ' ', s, "left, no");
}

void	fixer(t_flag *flag, int min, int null, int s)
{
	char	a;
	char *temp;

	if (min && null)
		flag->str = ft_str_width(flag->str, '0', s, "right, no");
	else if (min && !(null))
		flag->str = ft_str_width_free(flag->str, ' ', s, "right, no");
	else if (null && !(min))
	{
		if ((flag->sharp && (flag->flag_5 == 'x' || flag->flag_5 == 'X')) ||
			*(flag->str) == '+' || *(flag->str) == '-' || *(flag->str) == ' ')
		{
			if (*(flag->str) == '+' || *(flag->str) == '-' || *(flag->str) == ' ')
			{
				a = *(flag->str);
				temp = flag->str;
				flag->str = ft_str_width(flag->str + 1, '0', s - 1, "left, no");
				free(temp);
				flag->str = ft_strjoin_fr_both(ft_strdup_n(&a, 1), flag->str);
			}
			else
			{
				temp = flag->str;
				flag->str = ft_str_width(flag->str + 2, '0', s - 2, "left, no");
				free(temp);
				if (flag->flag_5 == 'X')
					flag->str = ft_strjoin_free_2("0X", flag->str);
				else
					flag->str = ft_strjoin_free_2("0x", flag->str);
			}
		}
		else
			flag->str = ft_str_width_free(flag->str, '0', s, "left, no");
	}
	else
		flag->str = ft_str_width_free(flag->str, ' ', s, "left, no");
}

int	fixer_num(t_flag *flag)
{
	int	len;
	int	c;

	c = 0;
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
	if (flag->after_dot)
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
			fixer(flag, flag->min, flag->null, flag->after_dot);
	}
	if (c)
		fixer_free(flag, flag->min, flag->null, flag->before_dot);
	else
		fixer(flag, flag->min, flag->null, flag->before_dot);
	return (0);
}
