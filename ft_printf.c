/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:46:41 by gly               #+#    #+#             */
/*   Updated: 2018/12/28 13:25:58 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_printstr(char *format)
{
	int	len;

	len = ft_strlen(format);
	write(1, format, len);
	return (len);
}

int			ft_printf2(const char *format, va_list ap, t_lpf **lst)
{
	size_t		index;

	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%' && ++index)
		{
			if (!ft_addlpf_per(lst, format, ap, &index))
			{
				ft_rmlpf_all(*lst);
				return (-1);
			}
		}
		if (!(index = ft_addlpf_str(lst, format, index)))
			return (-1);
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	t_lpf		*lst;
	va_list		ap;
	int			ret;

	lst = NULL;
	if (ft_strchr(format, '%') == NULL)
		return (ft_printstr((char *)format));
	va_start(ap, format);
	if (ft_printf2(format, ap, &lst) == -1)
		return (-1);
	va_end(ap);
	ret = ft_printlpf_all(lst);
	ft_rmlpf_all(lst);
	return (ret);
}
