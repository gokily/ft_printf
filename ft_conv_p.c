/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:49:42 by gly               #+#    #+#             */
/*   Updated: 2019/01/10 10:30:23 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_add_width(char *ret, t_lpf *node, size_t len)
{
	if (node->width > len)
	{
		ret = node->flag & MINUS ?
			ft_strjoinfree(ret, ft_strspace(node->width - len), RIGHT | LEFT) :
			ft_strjoinfree(ft_strspace(node->width - len), ret, RIGHT | LEFT);
	}
	return (ret);
}

char		*ft_conv_p(t_lpf *node, va_list ap)
{
	size_t	addr;
	char	*ret;
	size_t	len;

	addr = va_arg(ap, size_t);
	if (!(ret = addr == 0 && node->flag & ACC ? ft_strzero(node->acc) :
		ft_size_t2a_base(addr, "0123456789abcdef")))
		return (NULL);
	len = ft_strlen(ret);
	if (node->acc > len && addr != 0)
	{
		ret = ft_strjoinfree(ft_strzero(node->acc - len), ret, LEFT | RIGHT);
		if (ret == NULL)
			return (NULL);
		len = node->acc;
	}
	if (!(ret = ft_strjoinfree("0x", ret, RIGHT)))
		return (NULL);
	len = ft_strlen(ret);
	ret = ft_add_width(ret, node, len);
	node->len = ft_strlen(ret);
	return (ret);
}
