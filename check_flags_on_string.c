#include "head.h"

void flag_nuller(t_flag *flag)
{
	flag->plus = 0;
	flag->minus = 0;
	flag->lattice = 0;
	flag->dot = 0;
	flag->space = 0;
	flag->before_dot = 0;
	flag->after_dot = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->L = 0;
	flag->flag = 0;
	flag->before_flag = 0;
	flag->after_flag = 0;
}


int ok(char *str, t_flag *flag)
{
	int num;
	int atoi_log;

	num = 1;
	atoi_log = 0;
	if (*str == '+')
		flag->plus++;
	else if (*str == '-')
		flag->minus++;
	else if (*str == '#')
		flag->lattice++;
	else if (*str == '.')
		flag->dot++;
	else if (*str == ' ')
		flag->space++;
	else if (*str == 'l')
	{
		if (str[1] == 'l')
		{
			num++;
			flag->ll++;
		}
		else
			flag->l++;
	}
	else if (*str == 'h')
	{
		if (str[1] == 'h')
		{
			num++;
			flag->hh++;
		}
		else
			flag->h++;
	}
	else if (*str == 'L')
		flag->L++;
	else if (*str >= 0 && *str <= 9)
	{
		if (flag->dot == 1)
		{
			if (flag->after_flag)
				return (0);
			flag->after_dot = ft_atoi(str);
			flag->after_flag = 1;
			if (ft_math_numlen_long((long int)flag->after_dot) > 1)
				num += ft_math_numlen_long((long int)flag->after_dot) - 1;
		}
		else if (!flag->dot)
		{
			flag->before_flag = 1;
			flag->before_dot = ft_atoi(str);
			if (ft_math_numlen_long((long int)flag->before_dot) > 1)
				num += ft_math_numlen_long((long int)flag->before_dot) - 1;
		}
		else
			return (0);
	}
	else
		return (0);
	return (num);
}

int only_1_flag(t_flag *flag)
{
	if (flag->plus > 1 || flag->minus > 1 || flag->lattice > 1 \
	|| flag->dot > 1 || flag->space > 1 || flag->l > 1 || flag->ll > 1 \
	|| flag->h > 1 || flag->hh > 1 || flag->L > 1)
		return (0);
	return (1);
}

int is_it_flag(char *str, t_flag *flag)
{
	if (*str == 'c' || *str == 'f' || *str == 'd' || *str == 's' \
	|| *str == '%')
	{
		flag->flag = *str;
		return (1);
	}
	return (0);
}

int links_flag_prove(t_flag *flag)
{
	return (1);
}

int check_flags(char *str, t_flag *flag)
{
	size_t index;
	size_t sum;

	index = 0;
	flag_nuller(flag);
	while (str[index])
	{
		if (!(sum = ok(str + index, flag)))
		{
			if (!(sum = is_it_flag(str, flag)))
				return (0);
			else
			{
				index += sum;
				break ;
			}
		}
		index += sum;
	}
	if (!only_1_flag(flag) || !links_flag_prove(flag))
		return (0);
	return (sum);
}
