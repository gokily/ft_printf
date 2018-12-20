/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:49:42 by gly               #+#    #+#             */
/*   Updated: 2018/12/20 16:11:44 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_p(t_lpf *node, va_list ap)
{
	size_t	addr;
	char	*ret;

	addr = va_arg(ap, size_t);
	ret = addr == 0 && node->flag & ACC ? ft_strzero(node->acc) :
		ft_size_t2a_base(addr, "0123456789abcdef");
	if (!(ret = ft_strjoinfree("0x", ret, RIGHT)))
		return (NULL);
	addr = ft_strlen(ret);
	if (node->width > addr)
	{
		ret = node->flag & MINUS ?
			ft_strjoinfree(ret, ft_strspace(node->width - addr), RIGHT | LEFT) :
			ft_strjoinfree(ft_strspace(node->width - addr), ret, RIGHT | LEFT);
	}
	node->len = ft_strlen(ret);
	return (ret);
}
