#include "head.h"

char *lst_print_cs(void *point)
{
	t_list *lst;
	t_list *result;

	lst = (t_list *)point;
	if (!lst)
		return (ft_strdup("[NULL]"));
	result = ft_lstnew("[", 1);
	while (lst)
	{
		if (lst->content)
			ft_lstadd(&result, ft_lstnew(lst->content, lst->content_size));
		else
			ft_lstadd(&result, ft_lstnew("(NULL)", 6));
		if (lst->next)
			ft_lstadd(&result, ft_lstnew("]->[", 4));
		lst = lst->next;
	}
	ft_lstadd(&result, ft_lstnew("]", 1));
	return (ft_lst_strjoin_free_cs(ft_lst_turn(result)));
}
