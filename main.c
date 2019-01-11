/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:42:33 by gly               #+#    #+#             */
/*   Updated: 2019/01/10 11:52:14 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "libft/libft.h"
#include <limits.h>

int	main(void)
{
	int	a;
	int b;
	a = printf("%4.3s %4.0p\n", 0, &a);
	b = ft_printf("%4.3s %4.0p\n", 0, &a);
	if (a == b)
		puts("C'est bon");
	return (0);
}

