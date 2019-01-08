/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlpf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:52:08 by gly               #+#    #+#             */
/*   Updated: 2019/01/08 12:04:43 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

size_t	ft_addlpf_str(t_lpf **lpf, const char *format, size_t index)
{
	size_t	i;
	t_lpf	*node;

	i = index;
	if (!(node = ft_lpfnew()))
		return (0);
	while (format[i] != '\0' && format[i] != '%')
		i++;
	if (!(node->str = ft_strndup(format + index, i - index)))
	{
		free(node);
		return (0);
	}
	node->len = i - index;
	lpf = ft_lpf_push(lpf, node);
	return (i);
}
