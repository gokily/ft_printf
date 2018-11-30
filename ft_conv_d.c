/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:12:59 by gly               #+#    #+#             */
/*   Updated: 2018/11/27 15:23:03 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

#include <stdio.h>

static char	*ft_add_flags(char *ret, t_lpf *node, long long nb)
{
	if (nb < 0)
		return (ft_strjoinfree("-", ret, RIGHT));
	if (node->flag & PLUS)
		return (ft_strjoinfree("+", ret, RIGHT));
	if (node->flag & SPACE)
		return (ft_strjoinfree(" ", ret, RIGHT));
	return (ret);
}

static char	*ft_add_width(char *ret, t_lpf *node, size_t len, long long nb)
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
		{
			ret = ft_add_flags(ret, node, nb);
			return (ft_strjoinfree(ft_strspace(n), ret, RIGHT | LEFT));
		}
	}
	if (!(node->flag & ACC) && node->flag & ZERO)
		ret = ft_add_flags(ret, node, nb);
	return (ret);
}

static char	*ft_conv_d2(long long nb, t_lpf *node)
{
	char	*ret;
	size_t		len;

	if (node->flag & CHAR)
		nb = (char)nb;
	else if (node->flag & SHORT)
		nb = (short)nb;
	len = ft_longlonglen_base(nb, 10);
	if (!(ret = ft_ll2a_pf(nb)))
		return (NULL);
	if (node->acc > len)
	{
		ret = ft_strjoinfree(ft_strzero(node->acc - len), ret, LEFT | RIGHT);
		if (ret == NULL)
			return (NULL);
		len = node->acc;
	}
	if (node->flag & ACC || !(node->flag & ZERO))
		if (!(ret = ft_add_flags(ret, node, nb)))
			return (NULL);
	len += (nb < 0 || node->flag & PLUS || node->flag & SPACE) ? 1 : 0;
	if (!(ret = ft_add_width(ret, node, len, nb)))
		return (NULL);
	return (ret);
}

char	*ft_conv_d(t_lpf *node, va_list ap)
{
	char	*ret;

	if (node->flag & LLONG)
		ret = ft_conv_d2(va_arg(ap, long long), node);
	else if(node->flag & LONG)
		ret = ft_conv_d2(va_arg(ap, long), node);
	else
		ret = ft_conv_d2(va_arg(ap, int), node);
	return (ret);
}