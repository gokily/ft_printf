/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:42:33 by gly               #+#    #+#             */
/*   Updated: 2019/03/04 09:33:31 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "libft/libft.h"
#include <limits.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;
	int		ret;

	str = strdup("test %d\n");
	ret = printf(str, 56);
	puts("");
	printf("ret is %d\n", ret);
	ret = ft_printf(str, 56);
	puts("");
	printf("ret is %d\n", ret);
	free(str);
	return (0);
}

