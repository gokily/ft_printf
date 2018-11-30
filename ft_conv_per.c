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
		{
			return (ft_strjoinfree(ft_strspace(n), ret, RIGHT | LEFT));
		}
	}
	return (ret);
}

char	*ft_conv_per(t_lpf *node, va_list ap)
{
	char	*ret;
	size_t		len;
	
	(void)ap;
	ret = ft_strdup("%");
	len = 1;
	if (node->acc > len)
	{
		ret = ft_strjoinfree(ft_strzero(node->acc - len), ret, LEFT | RIGHT);
		if (ret == NULL)
			return (NULL);
		len = node->acc;
	}
	if (!(ret = ft_add_width(ret, node, len)))
		return (NULL);
	return (ret);
}