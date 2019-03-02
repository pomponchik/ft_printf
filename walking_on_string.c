#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

size_t just_to_print_len(char *str, int *persent_indicate)
{
	size_t index;

	index = 0;
	while (str[index] && str[index] != '%')
		index++;
	if (str[index] == '%')
		*persent_indicate = 1;
	else
		*persent_indicate = 0;
	return (index);
}

char *ft_putstr_len(char *str, size_t len)
{
	write(1, str, len);
	if (!len)
		return (NULL);
	return (str + len);
}

size_t recognise_types(char *str, char *current_argument)
{
	return (3);
}

void print_type(char *type, char *current_argument)
{
	ft_putstr_len(current_argument, 5);
	return ;
}

char *post_persent(char *str, char *current_argument)
{
	size_t type_len;

	if ((type_len = recognise_types(str, current_argument)))
		print_type(str, current_argument);
	return (str + type_len);
}

void ft_printf(const char *format, ...)
{
	char *str;
	int persent_indicate;
	va_list arguments;
	char *current_argument;

	str = (char *)format;
	va_start(arguments, format);
	while (str)
	{
		current_argument = va_arg(arguments, char *);
		str = ft_putstr_len(str, just_to_print_len(str, &persent_indicate));
		if (persent_indicate)
			str = post_persent(str, current_argument);
	}
	va_end(arguments);
}

int main()
{
	char *str = "ha-ha, lol% 1234567890 %1234567890\n";
	ft_printf(str, 12, " oh2 ");
	return 0;
}
