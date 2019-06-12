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
#include "head.h"

int	main()
{
	// int a;
	// int b;
	//ft_printf("%x", 42);
//	ft_printf("%       ");
	//ft_printf("gfdhbfjd\n");
	// ft_printf("%x", 12);
	// ft_printf("\n12345 %#10Xtttt\n", 12);
	//printf("%sddd\n", ft_strdup(""));

	//printf("%s\n", ft_itoa_long_long(ft_maxmin("long long", "min")));
  //a = ft_printf("%c", 0);
	//b = printf("%c", 0);
	//printf("\n %d %d\n", a , b);
	//printf("%p\n", &a);
	//ft_printf("ft %p\n", &a);
	//ft_printf("%-5.10o", 2500);
	 //ft_printf("%.10d", 4242);
	// ft_printf("%2c", 0);
	// ft_printf("@moulitest: %.x %.0x\n", 0, 0);
	// ft_printf("%lx\n", 4294967296);
	// ft_printf("%s\n", NULL);
	//ft_printf("%   %\n");
//
// 16_conv_c.spec.c
//
printf("43_length_modif_hh.spec.c\n");
ft_printf("%hhO, %hhO\n", 0, USHRT_MAX);
printf("%hhO, %hhO\n", 0, USHRT_MAX);
//
// 50_min_width.spec.c
printf("50_min_width.spec.c\n");
ft_printf("ft{%10R}\n");
printf("pf{%10R}\n");
//
// 52_min_width_flag_zero.spec.c
//
printf("53_min_width_non_valid_conv segfault\n");
ft_printf("{%-15Z}\n", 123);
printf("{%-15Z}\n", 123);
//
printf("60_flag_sharp.spec.c\n");
ft_printf("%#o\n", 0);
printf("%#o\n", 0);
ft_printf("%#O\n", 1);
printf("%#O\n", 1);

//

// ft_printf("{%f}{%f}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
// printf("{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
//

//
printf("69_flag_mix.spec.c\n");
ft_printf("{%+03d}\n", 0);
ft_printf("{% 03d}\n", 0);
//
printf("70_precision_for_diu.spec.c\n");
ft_printf("1%15.4d\n", 42);
printf("2%15.4d\n", 42);
ft_printf("1%15.4d\n", 424242);
printf("2%15.4d\n", 424242);
// ft_printf("ab%15.4d\n", -42);
// printf("ab%15.4d\n", -42);
ft_printf("1%15.4d\n", -424242);
printf("2%15.4d\n", -424242);
ft_printf("1%.u, %.0u\n", 0, 0);
printf("2%.u, %.0u\n", 0, 0);
ft_printf("1%15.4u\n", 42);
printf("2%15.4u\n", 42);
ft_printf("1%15.4u\n", 424242);
printf("2%15.4u\n", 424242);
//
printf("71_precision_for_oOxX.spec.c\n");
ft_printf("%15.4o\n", 42);
printf("%15.4o\n", 42);
ft_printf("%15.4o\n", 424242);
printf("%15.4o\n", 424242);
ft_printf("%.4O\n", 42);
printf("%.4O\n", 42);
ft_printf("%15.4O\n", 42);
printf("%15.4O\n", 42);
ft_printf("%4.15O\n", 42);
printf("%4.15O\n", 42);
ft_printf("%.o, %.0O\n", 0, 0);
printf("%.o, %.0O\n", 0, 0);
ft_printf("%15.4x\n", 42);
printf("%15.4x\n", 42);
ft_printf("%15.4x\n", 424242);
printf("%15.4x\n", 424242);
ft_printf("%15.4X\n", 42);
printf("%15.4X\n", 42);
ft_printf("%15.4X\n", 424242);
printf("%15.4X\n", 424242);

printf("72_precision_for_sS.spec.c\n");
ft_printf("%15.4s/n", "42");
printf("%15.4s/n", "42");
ft_printf("%15.4s\n", "I am 42");
printf("%15.4s\n", "I am 42");
ft_printf("%15.4s\n", "42 is the answer");
printf("%15.4s\n", "42 is the answer");
ft_printf("%4.s\n", "42");
printf("%15.4s\n", "42 is the answer");

// 73_precision_for_cC.spec.c

//
printf("74_precision_for_p.spec.c\n");
ft_printf("%.0p, %.p\n", 0, 0);
printf("%.0p, %.p\n", 0, 0);
ft_printf("%.5p\n", 0);
printf("%.5p\n", 0);
ft_printf("%9.2p\n", 1234);
printf("%9.2p\n", 1234);
ft_printf("%9.2p\n", 1234567);
printf("%9.2p\n", 1234567);
ft_printf("%2.9p\n", 1234);
printf("%2.9p\n", 1234);
ft_printf("%2.9p\n", 1234567);
printf("%2.9p\n", 1234567);

printf("79_precision_mixed_with_flags\n");
ft_printf("%.p, %.0p\n", 0, 0);
printf("%.p, %.0p\n", 0, 0);
ft_printf("{%05.c}\n", 0);
printf("{%05.c}\n", 0);
ft_printf("{%05.s}\n", 0);
printf("{%05.s}\n", 0);
ft_printf("{%05.Z}\n", 0);
printf("{%05.Z}\n", 0);
ft_printf("{%#.5x}\n", 1);
printf("{%#.5x}\n", 1);

printf("92_incomptbl_values_oOxX.spec\n");
ft_printf("% o|%+o\n", 42, 42);
printf("% o|%+o\n", 42, 42);
ft_printf("% x|%+x\n", 42, 42);
printf("% x|%+x\n", 42, 42);
ft_printf("% X|%+X\n", 42, 42);
printf("% X|%+X\n", 42, 42);

// ft_printf_test(58756,0x7fffcb8f63c0) malloc: *** error for object 0x7fcc1bf04570: pointer being freed was not allocated
//*** set a breakpoint in malloc_error_break to debug


	// ft_printf("%O\n", LONG_MAX);
	// printf("%O\n", LONG_MAX);
	// ft_printf("%O\n", LONG_MIN);
	// printf("%O\n", LONG_MIN);



	// ft_printf("%o, %ho, %hho\n", -42, -42, -42);
	// printf("%o, %ho, %hho\n", -42, -42, -42);
	// ft_printf("% x|%+x\n", 42, 42);
	// printf("% x|%+x\n", 42, 42);
	// ft_printf("% X|%+X\n", 42, 42);
	// printf("% X|%+X\n", 42, 42);
	return (0);
}
