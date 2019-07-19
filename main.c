#include "head.h"

int main()
{
  t_list *lst;

  lst = NULL;
  int i = 0;
  while (i < 100)
  {
    char *str = ft_itoa(i);
    size_t size = ft_strlen(str);
    ft_lstadd_to_end(&lst, ft_lstnew_no_copy(str, size));
    ft_lstadd_to_end(&lst, ft_lstnew_no_copy(str, size));
    i++;
  }
  i *= -1;
  ft_printf("%b\n", &i, sizeof(int));
  // ft_printf("{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
  return (0);
}
