/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:01:19 by gly               #+#    #+#             */
/*   Updated: 2019/01/08 11:15:54 by gly              ###   ########.fr       */
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
		else if ((node->flag & ZERO) && !(node->flag & ACC))
			ret = ft_strjoinfree(ft_strzero(n), ret, RIGHT | LEFT);
		else
			ret = ft_strjoinfree(ft_strspace(n), ret, RIGHT | LEFT);
	}
	return (ret);
}

static char	*ft_conv_u2(unsigned long long nb, t_lpf *node)
{
	char	*ret;
	size_t	len;

	if (node->flag & CHAR)
		nb = (unsigned char)nb;
	else if (node->flag & SHORT)
		nb = (unsigned short)nb;
	ret = nb == 0 && node->flag & ACC && node->acc == 0 ? ft_strdup("") :
		ft_ull2a(nb);
	if (!ret)
		return (NULL);
	len = ft_strlen(ret);
	if (node->acc > len)
	{
		ret = ft_strjoinfree(ft_strzero(node->acc - len), ret, LEFT | RIGHT);
		if (ret == NULL)
			return (NULL);
		len = node->acc;
	}
	if (!(ret = ft_add_width(ret, node, len)))
		return (NULL);
	node->len = ft_strlen(ret);
	return (ret);
}

char		*ft_conv_u(t_lpf *node, va_list ap)
{
	char	*ret;

	if (node->flag & JAY)
		ret = ft_conv_u2(va_arg(ap, uintmax_t), node);
	else if (node->flag & LLONG)
		ret = ft_conv_u2(va_arg(ap, unsigned long long), node);
	else if (node->flag & ZED)
		ret = ft_conv_u2(va_arg(ap, size_t), node);
	else if (node->flag & LONG)
		ret = ft_conv_u2(va_arg(ap, unsigned long), node);
	else if (node->flag & TEE)
		ret = ft_conv_u2(va_arg(ap, ptrdiff_t), node);
	else
		ret = ft_conv_u2(va_arg(ap, unsigned int), node);
	if (ret != NULL)
		node->len = ft_strlen(ret);
	return (ret);
}
