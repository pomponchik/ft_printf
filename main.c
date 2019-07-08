#include "head.h"

int main()
{
	t_list *lst = NULL;
	int i = 0;
	while (i < 100)
	{
		char *a = ft_itoa(i);
		ft_lstadd(&lst, ft_lstnew(a, ft_strlen(a)));
		i++;
	}
	ft_printf("%s\n", lst_print_cs(lst));
	return (0);
}
