/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 22:23:51 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/12 22:23:53 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct			s_flags
{
	char plus;
	char minus;
	char lattice;
	char dot;
	char space;
	int before_dot;
	char before_flag;
	int after_dot;
	char after_flag;
	char l;
	char ll;
	char h;
	char hh;
	char L;
	char flag;
}						t_flag;

int ft_printf(const char *format, ...);
char *post_persent(char *str, va_list *arguments, int *count);
char *ft_putstr_len(char *str, size_t len);
size_t just_to_print_len(char *str, int *persent_indicate, int *count);
size_t out_from_flag(t_flag *flag, va_list *arguments);

int check_flags(char *str, t_flag *flag);
int links_flag_prove(t_flag *flag);
int is_it_flag(char *str, t_flag *flag);
int only_1_flag(t_flag *flag);
int ok(char *str, t_flag *flag);
void flag_nuller(t_flag *flag);

#endif
