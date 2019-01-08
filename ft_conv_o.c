/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:56:01 by gly               #+#    #+#             */
/*   Updated: 2019/01/08 13:18:48 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_checkpound(char *ret, t_lpf *node, unsigned long long nb,
		size_t len)
{
	if (node->flag & POUND)
	{
		if ((nb != 0 && len > node->acc + 1)
				|| (nb == 0 && node->flag & ACC && node->acc == 0))
			return (ft_strjoinfree("0", ret, RIGHT));
	}
	return (ret);
}

static char	*ft_add_width(char *ret, t_lpf *node, size_t len,
		unsigned long long nb)
{
	size_t	n;

	n = node->width > len ? node->width - len : 0;
	if (n != 0)
	{
		if (node->flag & MINUS)
		{
			ret = ft_checkpound(ret, node, nb, len);
			return (ft_strjoinfree(ret, ft_strspace(n), RIGHT | LEFT));
		}
		else if ((node->flag & ZERO) && !(node->flag & ACC))
		{
			ret = ft_strjoinfree(ft_strzero(n), ret, RIGHT | LEFT);
			return (ft_checkpound(ret, node, nb, len));
		}
		else
		{
			ret = ft_checkpound(ret, node, nb, len);
			return (ft_strjoinfree(ft_strspace(n), ret, RIGHT | LEFT));
		}
	}
	return (ft_checkpound(ret, node, nb, len));
}

static char	*ft_conv_o2(unsigned long long nb, t_lpf *node)
{
	char	*ret;
	size_t	len;

	if (node->flag & CHAR)
		nb = (unsigned char)nb;
	else if (node->flag & SHORT)
		nb = (unsigned short)nb;
	if (nb == 0 && node->flag & ACC && node->acc == 0)
		return (ft_add_width(ft_strdup(""), node, 0, 0));
	len = ft_ulllen_base(nb, 8);
	if (!(ret = ft_ull2a_base(nb, "01234567")))
		return (NULL);
	if (node->acc > len)
	{
		ret = ft_strjoinfree(ft_strzero(node->acc - len), ret, LEFT | RIGHT);
		if (ret == NULL)
			return (NULL);
		len = node->acc;
	}
	else if (node->flag & POUND)
		len++;
	if (!(ret = ft_add_width(ret, node, len, nb)))
		return (NULL);
	return (ret);
}

char		*ft_conv_o(t_lpf *node, va_list ap)
{
	char	*ret;

	if (node->flag & JAY)
		ret = ft_conv_o2(va_arg(ap, uintmax_t), node);
	else if (node->flag & LLONG)
		ret = ft_conv_o2(va_arg(ap, unsigned long long), node);
	else if (node->flag & ZED)
		ret = ft_conv_o2(va_arg(ap, size_t), node);
	else if (node->flag & LONG)
		ret = ft_conv_o2(va_arg(ap, unsigned long), node);
	else if (node->flag & TEE)
		ret = ft_conv_o2(va_arg(ap, ptrdiff_t), node);
	else
		ret = ft_conv_o2(va_arg(ap, unsigned int), node);
	if (ret != NULL)
		node->len = ft_strlen(ret);
	return (ret);
}
