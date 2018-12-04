#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_add_width(char *ret, t_lpf *node, size_t len)
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
			ret = ft_strjoinfree(ft_strspace(n), ret, RIGHT | LEFT);
	}
	return (ret);
}

static char	*ft_conv_u2(unsigned long long nb, t_lpf *node)
{
	char	*ret;
	size_t		len;

	if (node->flag & CHAR)
		nb = (char)nb;
	else if (node->flag & SHORT)
		nb = (short)nb;
	len = ft_ulllen_base(nb, 10);
	ret = ft_ull2a(nb);
	if (!ret)
		return (NULL);
	if (node->acc > len)
	{
		ret = ft_strjoinfree(ft_strzero(node->acc - len), ret, LEFT | RIGHT);
		if (ret == NULL)
			return (NULL);
		len = node->acc;
	}
	if (!(ret = ft_add_width(ret, node, len)))
		return (NULL);
	node->len = ft_strlen(ret);
	return (ret);
}

char	*ft_conv_u(t_lpf *node, va_list ap)
{
	char	*ret;

	if (node->flag & LLONG)
		ret = ft_conv_u2(va_arg(ap, unsigned long long), node);
	else if(node->flag & LONG)
		ret = ft_conv_u2(va_arg(ap, unsigned long), node);
	else
		ret = ft_conv_u2(va_arg(ap, unsigned int), node);
	return (ret);
}
