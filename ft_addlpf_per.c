/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlpf_per.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:50:21 by gly               #+#    #+#             */
/*   Updated: 2019/02/22 10:35:39 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_convtab.h"
#include <stdlib.h>

static char	*ft_va2str(t_lpf *node, va_list ap)
{
	size_t		i;

	i = 0;
	while (g_convtab[i].type != '\0')
	{
		if (g_convtab[i].type == node->type)
			return (g_convtab[i].fct(node, ap));
		i++;
	}
	return (NULL);
}

static void	ft_parse_mod(t_lpf *node, const char *format)
{
	if (format[0] == 'h')
	{
		if (format[1] == 'h')
			node->flag |= CHAR;
		else if ((node->flag & CHAR) == 0)
			node->flag |= SHORT;
	}
	if (format[0] == 'l')
	{
		if (format[1] == 'l')
			node->flag |= LLONG;
		else if ((node->flag & LLONG) == 0)
			node->flag |= LONG;
	}
	if (*format == 'L')
		node->flag |= LDOUBLE;
	if (*format == 'j')
		node->flag |= JAY;
	if (*format == 'z')
		node->flag |= ZED;
	if (*format == 't')
		node->flag |= TEE;
	return ;
}

static char	ft_parse_flag(t_lpf *node, const char *format, size_t *index)
{
	while (format[*index] && ft_strchr(FLAG, format[*index]))
	{
		if (format[*index] == '#')
			node->flag |= POUND;
		if (format[*index] == '+')
			node->flag |= PLUS;
		if (format[*index] == '-')
			node->flag |= MINUS;
		if (format[*index] == ' ')
			node->flag |= SPACE;
		if (format[*index] == '0' && ft_isdigit(format[*index - 1]) == 0)
			node->flag |= ZERO;
		if (ft_isdigit(format[*index]) && format[*index] != 0
				&& node->width == 0)
			node->width = ft_atoi_pf(format, index);
		if (format[*index] == '.')
		{
			node->flag |= ACC;
			(*index)++;
			node->acc = ft_atoi_pf(format, index);
		}
		ft_parse_mod(node, format + *index);
		(*index)++;
	}
	return (ft_strchr(CONV, format[*index]) != NULL ? format[*index] : 0);
}

size_t		ft_addlpf_per(t_lpf **lpf, const char *format, va_list ap,
		size_t *index)
{
	t_lpf *node;

	if (!(node = ft_lpfnew()))
		return (0);
	if (!(node->type = ft_parse_flag(node, format, index)))
	{
		free(node);
		node = NULL;
		if ((*index = ft_addlpf_str(lpf, format, *index)) == 0)
			return (0);
		return (1);
	}
	if (!(node->str = ft_va2str(node, ap)))
	{
		free(node);
		node = NULL;
		return (0);
	}
	(*index)++;
	lpf = ft_lpf_push(lpf, node);
	return (1);
}
