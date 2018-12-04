/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:12:59 by gly               #+#    #+#             */
/*   Updated: 2018/12/04 15:01:45 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_fill_c(t_lpf *node, char *ret, char c, size_t len)
{
	if (node->flag & MINUS)
		ret[0] = c;
	else
		ret[len - 1] = c;
	return (ret);
}

char		*ft_conv_c(t_lpf *node, va_list ap)
{
	char	*ret;
	size_t	len;
	char	c;

	c = va_arg(ap, int);
	len = node->width > 1 ? node->width : 1;
	if (!(ret = ft_strspace(len)))
		return (NULL);
	node->len = len;
	return (ft_fill_c(node, ret, c, len));
}
