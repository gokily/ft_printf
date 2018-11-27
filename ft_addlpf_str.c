#include "ft_printf.h"

size_t ft_addlpf_str(t_lpf **lpf, const char *format, size_t index)
{
	size_t	i;
	t_lpf		*node;

	i = index;
	if (!(node = ft_lpfnew()))
		return (0);
	while (format[i] != '\0' && format[i] != '%')
		i++;
	if(!(node->str = ft_strndup(format + index, i - index)))
		return (0);
	node->ret = i - index;
	lpf = ft_lpf_push(lpf, node);
	return (i);
}
