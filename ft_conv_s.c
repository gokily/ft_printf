/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:49:28 by gly               #+#    #+#             */
/*   Updated: 2018/12/04 10:52:28 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_width(char *str, t_lpf *node)
{
	size_t	len;

	len = ft_strlen(str);
	len = node->flag & ACC && node->acc < len ? node->acc : len;
	str = ft_strndupfree(str, len);
	if (len >= node->width)
		return (str);
	if (node->flag & MINUS)
		return (ft_strjoinfree(str, ft_strspace(node->width - len), RIGHT | LEFT));
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
