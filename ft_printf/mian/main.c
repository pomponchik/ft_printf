/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:09:28 by kbethany          #+#    #+#             */
/*   Updated: 2019/05/04 15:20:33 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../head.h"


char *res(long double num)
{
	t_double fl;

	fl.d = num;
	fl.s_parts.exponent -= 16382;
	printf("%u\n", fl.s_parts.exponent);
	return (ft_strdup("1"));
}

int	main()
{
	res(152.5);
	return (0);
}
