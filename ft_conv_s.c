/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:49:28 by gly               #+#    #+#             */
/*   Updated: 2018/11/27 16:34:18 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_s(t_lpf *node, va_list ap)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = ft_strdup(va_arg(ap, char *))))
		return (NULL);
	len = ft_strlen(str);
	if (len == 0)
		return (str);
	if (len >= node->width)
		return (len > node->acc && node->flag & ACC ?
				ft_strndupfree(str, node->acc) : str);
	i = node->acc >= len ? node->width - len : node->width - node->acc;
	if (node->acc >= len)
	{
		return (node->flag & MINUS ?
				ft_strjoinfree(str, ft_strspace(i), LEFT | RIGHT) :
				ft_strjoinfree(ft_strspace(i), str, LEFT | RIGHT));
	}
	if (node->flag & MINUS)
		return (ft_strjoinfree(ft_strndupfree(str, node->acc), ft_strspace(i),
				   LEFT | RIGHT));
	return (ft_strjoinfree(ft_strspace(i), ft_strndupfree(str, node->acc),
			LEFT | RIGHT));
}
