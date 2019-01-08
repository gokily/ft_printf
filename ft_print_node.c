/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:00:41 by gly               #+#    #+#             */
/*   Updated: 2019/01/08 11:28:12 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print_node(t_lpf *node)
{
	printf("Flag is %16s\n", ft_size_t2a_base(node->flag, "01"));
	printf("Width is %lu\n", node->width);
	printf("Acc is %lu\n", node->acc);
	printf("Len is %lu\n", node->len);
	printf("Type is %c\n", node->type);
	printf("Str is %s\n", node->str);
}
