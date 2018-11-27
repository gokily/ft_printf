/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:12:59 by gly               #+#    #+#             */
/*   Updated: 2018/11/27 15:23:03 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_conv_c(t_lpf *node, va_list ap)
{
	char	*ret;
	size_t	i;
	char	c;

	i = 0;
	c = va_arg(ap, int);
	if (!(ret = malloc((node->width > 1 ? node->width : 1) + 1)))
		return (NULL);
	if (node->width > 1)
	{
		while (i < node->width)
		{
			ret[i] = ' ';
			i++;
		}
		if (node->flag & MINUS)
			ret[0] = c;
		else
			ret[i - 1] = c;
		ret[i] = '\0';
		return (ret);
	}
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}
