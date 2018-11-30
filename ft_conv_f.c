#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_add_flags(char *ret, t_lpf *node, long long nb)
{
	if (nb < 0)
		return (ft_strjoinfree("-", ret, RIGHT));
	if (node->flag & PLUS)
		return (ft_strjoinfree("+", ret, RIGHT));
	if (node->flag & SPACE)
		return (ft_strjoinfree(" ", ret, RIGHT));
	return (ret);
}

static char	*ft_add_width(char *ret, t_lpf *node, size_t len, long long nb)
{
	size_t n;

	n = node->width > len ? node->width - len : 0;
	if (n != 0)
	{
		if (node->flag & MINUS)
			ret = ft_strjoinfree(ret, ft_strspace(n), RIGHT | LEFT);
		else if ((node->flag & ZERO) && !(node->flag & ACC))
			ret = ft_strjoinfree(ft_strzero(n), ret, RIGHT | LEFT);
		else
		{
			ret = ft_add_flags(ret, node, nb);
			return (ft_strjoinfree(ft_strspace(n), ret, RIGHT | LEFT));
		}
	}
	return (ft_add_flags(ret, node, nb));
}

static char	*ft_assemblefloat(long double nb, long long_nb, t_lpf *node)
{
	char	*ret;
	size_t	i;
	char	*fract;
	size_t	acc;

	ret = ft_strjoinfree(ft_ll2a_pf(long_nb), ".", LEFT);
	i = 0;
	acc = node->flag & ACC ? node->acc : 6;
	if (!(fract = ft_strspace(acc)))
		return (NULL);
	while (i < acc)
	{
		fract[i] = 
	}

}

static char	*ft_conv_f2(long double nb, t_lpf *node)
{
	char	*ret;
	size_t		len;
	long 		long_nb;

	long_nb = (long)nb;
	nb -= (long double)long_nb;
	len = ft_longlonglen_base(long_nb, 10) + node->acc + 1;
	if (node->flag & ACC && node->acc == 0)
		ret = ft_ll2a_pf(long_nb + ft_round((int)(nb * 10))));
	else
	{
		ret = ft_assemblefloat(nb, long_nb, node)
	}

	if (!(ret = ft_ll2a_pf(long_nb)))
		return (NULL);
	if (node->flag & ACC)
	{
		ret = ft_strjoinfree(ft_strzero(node->acc - len), ret, LEFT | RIGHT);
		if (ret == NULL)
			return (NULL);
		len = node->acc;
	}
	len += (nb < 0 || node->flag & PLUS || node->flag & SPACE) ? 1 : 0;
	if (!(ret = ft_add_width(ret, node, len, nb)))
		return (NULL);
	return (ret);
}

char	*ft_conv_f(t_lpf *node, va_list ap)
{
	char	*ret;

	if (node->flag & LDOUBLE)
		ret = ft_conv_f2(va_arg(ap, long double), node);
	else
		ret = ft_conv_f2(va_arg(ap, double), node);
	return (ret);
}