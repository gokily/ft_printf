#include "ft_printf.h"

char	*ft_conv_p(t_lpf *node, va_list ap)
{
	size_t	addr;
	char	*ret;

	addr = va_arg(ap, size_t);
	if (!(ret = ft_size_t2a_base(addr, "0123456789abcdef")))
		return (NULL);
	if (!(ret = ft_strjoinfree("0x", ret, RIGHT)))
		return (NULL);
	addr = ft_strlen(ret);
	if (node->width > addr)
	{
		return (node->flag & MINUS ?
			ft_strjoinfree(ret, ft_strspace(node->width - addr), RIGHT | LEFT) :
			ft_strjoinfree(ft_strspace(node->width - addr), ret, RIGHT | LEFT));
	}
	return (ret);
}