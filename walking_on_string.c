#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"


typedef struct			s_types
{
	int ints;
	char chars;
	float floats;
	void *arg;
}						t_ype;

size_t just_to_print_len(char *str, int *persent_indicate, int *count)
{
	size_t index;

	index = 0;
	while (str[index] && str[index] != '%')
		index++;
	if (str[index] == '%')
	{
		*persent_indicate = 1;

	}
	else
		*persent_indicate = 0;
	//index--;
	*count += index;
	//printf("\n count: %d index: %d\n", *count, (int)index);
	return (index);
}

char *ft_putstr_len(char *str, size_t len)
{
	write(1, str, len);
	if (!len)
		return (NULL);
	return (str + len);
}


size_t recognise_types(char *str, va_list arguments)
{
	return 3;
}

char *post_persent(char *str, va_list *arguments, int *count)
{
	size_t type_len;
	char *current_argument;
	int c;
	char *tt;

	if (ft_strncmp("c", str, 1))
	{
		//printf("<>");
		//printf("\n count: %d, add 2 (1)\n", *count);
		c = va_arg(*arguments, int);
		ft_putchar(c);
		type_len = 2;
	}
	else if (ft_strncmp("%s", str, 1))
	{
		//printf("<>");
		tt = va_arg(*arguments, char *);
		//printf("\n count: %d, add 2 (2)\n", *count);
		ft_putstr(tt);
		type_len = 2;
	}
	else
	{
		type_len = 2;
		//printf("\n count: %d, add 2 (3)\n", *count);
		// current_argument = va_arg(arguments, char *);
		// if ((type_len = recognise_types(str, current_argument)))
		// 	print_type(str, current_argument);
	}
	*count += type_len;
	return (str + type_len);
}

int ft_printf(const char *format, ...)
{
	char *str;
	int persent_indicate;
	va_list arguments;
	char *current_argument;
	t_ype type;
	int count;

	count = 0;
	str = (char *)format;
	va_start(arguments, format);
	//va_arg(arguments, int);
	while (str)
	{
		//current_argument = va_arg(arguments, char *);
		str = ft_putstr_len(str, just_to_print_len(str, &persent_indicate, &count));

		if (persent_indicate)
			str = post_persent(str, &arguments, &count);
		//va_arg(arguments, int);
	}
	va_end(arguments);
	return (count);
}

int main()
{
	int c1;
	int c2;
	char *str = "1234567890 %c 1234567890 %s1234567890\n";
	char t = 't';
	c1 = ft_printf(str, t, "sssssssss");
	c2 = printf(str, t, "sssssssss");
	printf("%d %d\n", c1, c2);
	return 0;
}
