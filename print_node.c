#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

void	ft_print_node(t_lpf *node)
{
	printf("Flag is %16s\n", ft_size_t2a_base(node->flag, "01"));
	printf("Width is %lu\n", node->width);
	printf("Acc is %lu\n", node->acc);
	printf("Len is %lu\n", node->len);
	printf("Type is %c\n", node->type);
	printf("Str is %s\n", node->str);
}
