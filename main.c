/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:42:33 by gly               #+#    #+#             */
/*   Updated: 2019/03/04 13:43:25 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "libft/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		ret;
//	char	*str;

/*
	ft_printf("test01: ");
	ret = ft_printf("%s", "coucou");
	ft_printf("\n");

	ft_printf("test02: ");
	ret = ft_printf("%20s", "coucou");
	ft_printf("\n");

	ft_printf("test03: ");
	ret = ft_printf("%20s et et", "coucou");
	ft_printf("\n");

	ft_printf("test04: ");
	ret = ft_printf("et et %20s", "coucou");
	ft_printf("\n");

	ft_printf("test05: ");
	ret = ft_printf("et et %-20s", "coucou");
	ft_printf("\n");

	ft_printf("test06: ");
	ret = ft_printf("%.2s", "coucou");
	ft_printf("\n");
	
	ft_printf("test07: ");
	ret = ft_printf("%10.2s", "coucou");
	ft_printf("\n");
	
	ft_printf("test08: ");
	ret = ft_printf("%-10.2s", "coucou");
	ft_printf("\n");

	ft_printf("test09: ");
	ret = ft_printf("%aa.2s", "coucou");
	ft_printf("\n");

	ft_printf("test10: ");
	ret = ft_printf("%2s", "coucou");
	ft_printf("\n");

	ft_printf("test11: ");

	ret = ft_printf("%s %p %d %%%%%%", "coucou", NULL, 42);
	ft_printf("\n");

	ft_printf("%");
	ft_printf("%%%");
	ft_printf("");


	ft_printf("test12: ");
	ret = ft_printf("%+.6d", 123);
	ft_printf("\n");

	ft_printf("test13: ");
	ret = ft_printf("% .6d", 123);
	ft_printf("\n");

	ft_printf("test14: ");
	ret = ft_printf("%.6d", -123);
	ft_printf("\n");
	


	ft_printf("test15: ");
	ret = printf("%.3f", -123.34121);
	ret = ft_printf("%.3f", -123.34121);

	ft_printf("\n");
	*/
	long double i;
	
	i = 22522.128766342503253324532454324523499999999;
	//ft_printf("test16: ");
	ret = printf("%.25Lf\n", i);
	ret = ft_printf("%.25Lf", i);
	ft_printf("\n");
	
	
	return (0);
}

