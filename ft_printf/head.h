/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 22:23:51 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 20:15:16 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include <stdio.h>
# include <limits.h>
# include <ctype.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/includes/libft.h"
# include <errno.h>

typedef struct	s_flags
{
	t_list		*lst;
	int			null;
	int			min;
	int			sharp;
	int			plus;
	int			space;
	int			dot;
	int			before_dot;
	char		before_flag;
	int			after_dot;
	char		after_flag;
	char		l;
	char		ll;
	char		h;
	char		hh;
	char		flag_5;
	char		*str;
	int			i;
	char		ind_c;
}				t_flag;

int		flag_end(char str);
size_t	printer(t_flag *flag, uintmax_t i);
size_t	out_str(char *str);
void	first_flag_before(long long int i, t_flag *flag);
int		size_flag(char *a, t_flag *flag, size_t s);
int		second_flag(char *a, t_flag *flag);
void 	fixer_p(t_flag *flag);
void	fixer_free(t_flag *flag, int min, int null, int s);
void	fixer(t_flag *flag, int min, int null, int s);
int		fixer_num(t_flag *flag);
void	fixer_str(t_flag *flag, size_t *len);
size_t	flag_begin_chek(char *a, t_flag *flag);
char	*ft_strfilnew(size_t size, char a);
int		first_flag(long long int i, t_flag *flag, int f);
char	*ft_itoa_base_long(uintmax_t value, int base);
size_t	print_flag_d(t_flag *flag, va_list *arguments);
size_t	print_flag_p(t_flag *flag, va_list *arguments);
size_t	print_flag_x(t_flag *flag, va_list *arguments);
size_t	print_flag_o(t_flag *flag, va_list *arguments);
size_t	print_flag_u(t_flag *flag, va_list *arguments);
size_t	print_flag_f(t_flag *flag, va_list *arguments);
size_t	print_flag_sc(t_flag *flag, va_list *arguments);

int		ft_printf(const char *format, ...);
size_t	post_persent(char *str, va_list *arguments, t_list **lst);
size_t	just_to_print_len(char *str, int *persent_indicate, t_list **lst);
size_t	out_from_flag(t_flag *flag, va_list *arguments);

size_t	check_flags(char *str, t_flag *flag);
int		links_flag_prove(t_flag *flag);
int		is_it_flag(char *str1);
int		only_1_flag(t_flag *flag);
size_t	ok(char *str, t_flag *flag);
void	flag_nuller(t_flag *flag);

#endif
