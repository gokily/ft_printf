#include <string.h>

size_t		ft_size_tlen_base(size_t n, size_t base)
{
	size_t	i;
	size_t	power;

	i = 1;
	power = base;
	while ((n / power) > base)
	{
		i++;
		power *= base;
	}
	return (i);
}
