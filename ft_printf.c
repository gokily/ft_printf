/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:46:41 by gly               #+#    #+#             */
/*   Updated: 2018/11/27 15:56:43 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	t_lpf		*lst;
	va_list		ap;
	size_t			index;
	int			ret;

	index = 0;
	ret = 0;
	lst = NULL;
	va_start(ap, format);
	while (format[index] != '\0')
	{
		printf("%zu\n", index);
		if (format[index] == '%')
		{
			puts("Found a % !");
			index++;
			if (!ft_addlpf_per(&lst, format, ap, &index))
			{
				ft_rmlpf_all(lst);
				return (0);
			}
			puts("created a node");
		}
		printf("%zu\n", index);
		index = ft_addlpf_str(&lst, format, index);
		printf("%zu\n", index);
	}
	va_end(ap);
	ft_printlpf_all(lst, &ret);
	ft_rmlpf_all(lst);
	return (ret);
}
