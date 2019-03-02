#include <stdio.h>
#include <stdlib.h>

static int pluser(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static void minuser(int *value, int *base, int *minus)
{
	unsigned int temp;

	*minus = 0;
	if (*value < 0 && *base == 10)
		*minus = 1;
	else if (*value < 0)
	{
		temp = (unsigned int)(*value);
		*value = (int)temp;
	}
}

static int baser(int base, int len)
{
	int base_temp;

	base_temp = base;
	while (len - 1)
	{
		base *= base_temp;
		len--;
	}
	return (base);

}

char	*ft_itoa_base(int value, int base)
{
	char *letters;
	int minus;
	int len;
	char *result;

	if (base < 2 || base > 16)
		return (NULL);
	letters = "0123456789ABCDEF";
	len = 1;
	minuser(&value, &base, &minus);
	while (value / baser(base, len))
		len++;
	if (!(result = (char *)malloc(len + minus + 1)))
		return (NULL);
	result[len + minus] = '\0';
	if (minus)
	{
		result[0] = '-';
		len += minus;
		value *= -1;
	}
	while (len > minus)
	{
		result[len - 1] = letters[pluser(value % base)];
		len--;
		value /= base;
	}
	return (result);
}



int main()
{
	printf("%s\n", ft_itoa_base(-15, 16));
	printf("%d    %d\n", -10 / 100, 10 / 10);
	printf("%02X", -15);
	return 0;
}
