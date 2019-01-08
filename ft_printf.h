/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:14:36 by gly               #+#    #+#             */
/*   Updated: 2019/01/08 11:17:19 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

# define POUND		1
# define ZERO		1 << 1
# define MINUS		1 << 2
# define SPACE		1 << 3
# define PLUS		1 << 4
# define CAPS		1 << 5
# define ACC		1 << 6
# define CHAR		1 << 7
# define SHORT		1 << 8
# define LONG		1 << 9
# define LLONG		1 << 10
# define LDOUBLE	1 << 11
# define JAY		1 << 12
# define ZED		1 << 13
# define TEE		1 << 14
# define BUFFSIZE	1000
# define CONV		"csuidofFXxpb%"
# define FLAG		"#+- 0123456789.hlLjzt"

typedef struct		s_lpf
{
	struct s_lpf	*next;
	int				flag;
	size_t			width;
	size_t			acc;
	size_t			len;
	char			type;
	char			*str;
}					t_lpf;

int					ft_printf(const char *format, ...);

long long			ft_printlpf_all(t_lpf *lpf);
t_lpf				*ft_lpfnew(void);
t_lpf				**ft_lpf_push(t_lpf **lpf, t_lpf *node);
void				ft_rmlpf_all(t_lpf *lst);
void				ft_error(t_lpf *lst);

size_t				ft_addlpf_per(t_lpf **lpf, const char *format, va_list ap,
		size_t *index);
size_t				ft_addlpf_str(t_lpf **lpf, const char *format,
		size_t index);

int					ft_is_arg(char c);
char				*ft_strspace(size_t len);
char				*ft_strzero(size_t len);
char				*ft_itoa_pf(long long n, t_lpf *node);
size_t				ft_atoi_pf(const char *str, size_t *index);
char				*ft_ll2a_pf(long long n);
void				ft_print_node(t_lpf *node);

#endif
