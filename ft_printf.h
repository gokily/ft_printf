
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>


# include <stdio.h>

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
# define OCTAL		1 << 11
# define HEX_L		1 << 12
# define HEX_U		1 << 13
# define HEX_PTR	1 << 14
# define LDOUBLE	1 << 15

typedef struct	s_lpf
{
	struct s_lpf	*next;
	int				flag;
	size_t			width;
	size_t			acc;
	size_t			ret;
	char			type;
	char			*str;
}				t_lpf;

int			ft_printf(const char *format, ...);

void		ft_printlpf_all(t_lpf *lpf, int *ret);
t_lpf		*ftlpf_new(void);
t_lpf 		**ft_lpf_push(t_lpf **lpf, t_lpf *node);
void 		ft_rmlpf_all(t_lpf *lst);
void 		ft_error(t_lpf *lst);

size_t		ft_addlpf_per(t_lpf **lpf, const char *format, va_list ap, size_t *index);
size_t		ft_addlpf_str(t_lpf **lpf, const char *format, size_t index);

t_lpf		*ft_lpfnew(void);

int			ft_is_arg(char c);
char		*ft_strspace(size_t len);
char		*ft_strzero(size_t len);
char		*ft_convert_s(char *str, t_lpf *node);
char		*ft_convert_c(int c, t_lpf *node);
char		*ft_convert_p(unsigned long ptr, t_lpf *node);
char	*ft_convert_per(int c, t_lpf *node);
char	*ft_convert_d(long long n, t_lpf *node);
char	*ft_convert_u(unsigned long long n, t_lpf *node);
char	*ft_convert_o(unsigned long long n, t_lpf *node);
char	*ft_convert_hex(unsigned long long n, t_lpf *node);
char	*ft_convert_f(long double n, t_lpf *node);
char	*ft_strinsert(char *s1, char *s2, int index);
char	*ft_convert_acc(char *output, int len, t_lpf *node);
char	*ft_format(char *output, int len, t_lpf *node);
char	*ft_itoa_pf(long long n, t_lpf *node);

int		ft_abs(long long n);
int		ft_intlen_base_u(unsigned long long n, int base);

char	*ft_ll2a_pf(long long n);

void ft_print_node(t_lpf *node);

#endif
