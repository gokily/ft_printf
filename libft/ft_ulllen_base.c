#include <string.h>

size_t		ft_ulllen_base(unsigned long long n, unsigned int base)
{
	size_t		i;
	unsigned long long	power;

	i = 1;
	power = 1;
	while ((n / power) >= base)
	{
		i++;
		power *= base;
	}
	return (i);
}