/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_per.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:50:07 by gly               #+#    #+#             */
/*   Updated: 2019/01/08 12:16:00 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_add_width(char *ret, t_lpf *node, size_t len)
{
	size_t n;

	n = node->width > len ? node->width - len : 0;
	if (n != 0)
	{
		if (node->flag & MINUS)
			ret = ft_strjoinfree(ret, ft_strspace(n), RIGHT | LEFT);
		else if (node->flag & ZERO)
			ret = ft_strjoinfree(ft_strzero(n), ret, RIGHT | LEFT);
		else
			ret = ft_strjoinfree(ft_strspace(n), ret, RIGHT | LEFT);
	}
	return (ret);
}

char		*ft_conv_per(t_lpf *node, va_list ap)
{
	char	*ret;
	size_t	len;

	(void)ap;
	if (!(ret = ft_strdup("%")))
		return (NULL);
	len = 1;
	if (!(ret = ft_add_width(ret, node, len)))
		return (NULL);
	node->len = ft_strlen(ret);
	return (ret);
}
