/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:49:28 by gly               #+#    #+#             */
/*   Updated: 2019/02/21 14:55:45 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_add_width(char *str, t_lpf *node)
{
	size_t	len;

	len = ft_strlen(str);
	len = node->flag & ACC && node->acc < len ? node->acc : len;
	if (!(str = ft_strndupfree(str, len))
		return (NULL);
	if (len >= node->width)
		return (str);
	if (node->flag & MINUS)
	{
		return (ft_strjoinfree(str, ft_strspace(node->width - len),
					RIGHT | LEFT));
	}
	return (ft_strjoinfree(ft_strspace(node->width - len), str, RIGHT | LEFT));
}

char	*ft_conv_s(t_lpf *node, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		if (!(str = ft_strdup("(null)")))
			return (NULL);
	}
	else if (!(str = ft_strdup(str)))
		return (NULL);
	if (!(str = ft_add_width(str, node)))
		return (NULL);
	node->len = ft_strlen(str);
	return (str);
}
