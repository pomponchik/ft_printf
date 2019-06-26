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

int	main()
{
	ft_printf("ft%*d\n", 5, 42);
	printf("pf%*d\n", 5, 42);
	ft_printf("\nft{%*d}\n", -5, 42);
	printf("pf{%*d}\n", -5, 42);
	ft_printf("\nft{%*d}\n", 0, 42);
	printf("pf{%*d}\n", 0, 42);
	ft_printf("\nft{%*c}\n", -15, 0);
	printf("pf{%*c}\n", -15, 0);
	ft_printf("\nft{%.*d}\n", 5, 42);
	printf("pf{%.*d}\n", 5, 42);

	ft_printf("\nft{%.*d}\n", -5, 42);
	printf("pf{%.*d}\n", -5, 42);

	ft_printf("\nft{%.*d}\n", 0, 42);
	printf("pf{%.*d}\n", 0, 42);
	// // ft_printf("\nft{%.*s}\n", 5, "42");
	// // printf("pf{%.*s}\n", 5, "42");
	// // ft_printf("ft{%.*s}\n", -5, "42");
	// // printf("pf{%.*s}\n", -5, "42");
	// ft_printf("\nft{%.*s}\n", 0, "42");
	// printf("pf{%.*s}\n", 0, "42");
	// ft_printf("\nft{%*s}\n", 5, 0);
	// printf("pf{%*s}\n", 5, 0);
	// ft_printf("ft{%*p}\n", 10, 0);
	// printf("pf{%*p}\n", 10, 0);


	ft_printf("\nft%*.*d\n", 0, 3, 0);
	printf("pf%*.*d\n", 0, 3, 0);


	ft_printf("\nft{%05.*d}\n", -15, 42);
	printf("pf{%05.*d}\n", -15, 42);
	return (0);
}
