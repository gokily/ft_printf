/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convtab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:10:58 by gly               #+#    #+#             */
/*   Updated: 2018/12/20 16:08:23 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVTAB_H
# define FT_CONVTAB_H
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
char			*ft_conv_capu(t_lpf *node, va_list ap);
char			*ft_conv_o(t_lpf *node, va_list ap);
char			*ft_conv_capo(t_lpf *node, va_list ap);
char			*ft_conv_x(t_lpf *node, va_list ap);
char			*ft_conv_capx(t_lpf *node, va_list ap);
char			*ft_conv_f(t_lpf *node, va_list ap);
char			*ft_conv_per(t_lpf *node, va_list ap);

t_conv	g_convtab[] = {{'c', &ft_conv_c}, \
	{'s', &ft_conv_s}, \
	{'p', &ft_conv_p}, \
	{'d', &ft_conv_d}, \
	{'i', &ft_conv_d}, \
	{'u', &ft_conv_u}, \
	{'U', &ft_conv_capu}, \
	{'o', &ft_conv_o}, \
	{'O', &ft_conv_capo}, \
	{'x', &ft_conv_x}, \
	{'X', &ft_conv_capx}, \
	{'f', &ft_conv_f}, \
	{'F', &ft_conv_f}, \
	{'%', &ft_conv_per}, \
	{'\0', 0}};

#endif
