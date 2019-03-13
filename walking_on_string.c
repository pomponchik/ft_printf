#include "head.h"

size_t just_to_print_len(char *str, int *persent_indicate, int *count)
{
	size_t index;

	index = 0;
	while (str[index] && str[index] != '%')
		index++;
	if (str[index] == '%')
		*persent_indicate = 1;
	else
		*persent_indicate = 0;
	*count += index;
	return (index);
}

char *ft_putstr_len(char *str, size_t len)
{
	if (!len || !str)
		return (str);
	write(1, str, len);
	return (str + len);
}

size_t out_str(char *str)
{
	size_t len;

	len = ft_strlen(str);
	ft_putstr_len(str, len);
	return (len);
}

size_t out_from_flag(t_flag *flag, va_list *arguments)
{
	char *str;
	int integer;
	double fl;
	int temp;

	if (flag->flag == 's')
	{
		str = va_arg(*arguments, char *);
		return (out_str(str));
	}
	else if (flag->flag == 'c')
	{
		integer = va_arg(*arguments, int);
		ft_putchar(integer);
		return (1);
	}
	else if (flag->flag == 'd')
	{
		integer = va_arg(*arguments, int);
		str = ft_itoa(integer);
		temp = ft_strlen(str);
		ft_putstr_len(str, temp);
		free(str);
		return(temp);
	}
	else if (flag->flag == 'f')
	{
		fl = va_arg(*arguments, double);
		str = ft_itoa_double(fl);
		integer = ft_strlen(str);
		ft_putstr_len(str, integer);
		free(str);
		return(integer);
	}
	return (0);
}

char *post_persent(char *str, va_list *arguments, int *count)
{
	t_flag flag;
	size_t type_len;
	size_t out_len;

	//va_copy(flag.arguments, arguments);
	type_len = 0;
	if (!(type_len += check_flags(str + 1, &flag)))
	{
		return (str);
	}
	else
	{
		out_len = out_from_flag(&flag, arguments);
	}
	*count += out_len;
	return (str + type_len + 1);
}

int ft_printf(const char *format, ...)
{
	char *str;
	int persent_indicate;
	va_list arguments;
	char *current_argument;
	int count;

	count = 0;
	str = (char *)format;
	va_start(arguments, format);
	while (*str)
	{
		str = ft_putstr_len(str, just_to_print_len(str, &persent_indicate, &count));
		if (persent_indicate)
			str = post_persent(str, &arguments, &count);
	}
	va_end(arguments);
	return (count);
}

int main()
{
	int c1;
	int c2;
	char *str = "1234567890 %c 1234567890 %f 1234567890 %d %f %s\n";
	char t = 'v';
	char *d = "sssssssss";
	float ff = 14.56;
	int i = 1000;

	c1 = ft_printf(str, t, ff, i, ff, "abc");
	c2 = printf(str, t, ff, i, ff, "abc");
	printf("%d %d\n", c1, c2);
	// long double ld = 11511555555556666969876987698769876.0972;
	// printf("%LF, \n", ld/*, ft_itoa_long_double(ld)*/);
	return 0;
}
