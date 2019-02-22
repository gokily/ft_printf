/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:42:33 by gly               #+#    #+#             */
/*   Updated: 2019/02/21 15:51:09 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "libft/libft.h"
#include <limits.h>
#include <stdlib.h>

int	main(void)
{
	int b;
//	int a = 1;

	b = ft_printf("%p\n", 0);
	b = ft_printf("%p\n", 123);
	b = ft_printf("%-4%%i %d %u %o %x %X %p %s %c\n", 123, -123, -123, 123, 123, 123, 123, "wer", 'c');

	return (0);
}

