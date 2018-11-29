/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlpf_per.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:50:21 by gly               #+#    #+#             */
/*   Updated: 2018/11/27 15:58:02 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_convtab.h"
#include <stdlib.h>

#include <stdio.h>

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

static int	ft_parse_mod(t_lpf *node, const char *format)
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
	if (format[0] == 'L')
		node->flag |= LDOUBLE;
	return (1);
}

static char	ft_parse_flag(t_lpf *node, const char *format, size_t *index)
{
	while (format[*index] && ft_is_arg(format[*index]) == 0)
	{
		if (format[*index] == '#')
			node->flag |= SHARP;
		if (format[*index] == '+')
			node->flag |= PLUS;
		if (format[*index] == '-')
			node->flag |= MINUS;
		if (format[*index] == ' ')
			node->flag |= SPACE;
		if (format[*index] == '0' && ft_isdigit(format[*index - 1]) == 0)
			node->flag |= ZERO;
		if (format[*index] == '.')
		{
			node->flag |= ACC;
			node->acc = ft_atoi(format + *index + 1);
			while (ft_isdigit(format[*index]))
				(*index)++;
		}
		if (ft_isdigit(format[*index]) && format[*index] != 0 && node->width == 0)
			node->width = ft_atoi(format + *index);
		ft_parse_mod(node, format + *index);
		(*index)++;
	}
	return ((ft_is_arg(format[*index])) ? format[*index] : 0);
}

size_t		ft_addlpf_per(t_lpf **lpf, const char *format, va_list ap, size_t *index)
{
	t_lpf *node;

	if (!(node = ft_lpfnew()))
		return (0);
	if (!(node->type = ft_parse_flag(node, format, index)))
	{
		if (node->str)
			free(node->str);
		free(node);
		return (0);
	}
	if (!(node->str = ft_va2str(node, ap)))
	{
		if (node->str)
			free(node->str);
		free(node);
		return (0);
	}
	//ft_print_node(node);
	(*index)++;
	node->ret += ft_strlen(node->str);
	lpf = ft_lpf_push(lpf, node);
	return (1);
}
