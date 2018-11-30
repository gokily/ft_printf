/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convtab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:10:58 by gly               #+#    #+#             */
/*   Updated: 2018/11/27 14:51:28 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H
# include "ft_printf.h"

typedef char	*(*t_funptr)(t_lpf*, va_list);

typedef struct	s_conv
{
     char		type;
     t_funptr	fct;
}				t_conv;

char			*ft_conv_c(t_lpf *node, va_list ap);
char			*ft_conv_s(t_lpf *node, va_list ap);
char			*ft_conv_p(t_lpf *node, va_list ap);
char			*ft_conv_d(t_lpf *node, va_list ap);
char			*ft_conv_u(t_lpf *node, va_list ap);


t_conv	g_convtab[] = {{'c', &ft_conv_c}, \
	{'s', &ft_conv_s}, \
	{'p', &ft_conv_p}, \
	{'d', &ft_conv_d}, \
	{'i', &ft_conv_d}, \
	{'u', &ft_conv_u}, \
	{'\0', 0}};

#endif
