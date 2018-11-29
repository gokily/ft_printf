#include <string.h>

size_t		ft_longlonglen_base(long long n, int base)
{
	size_t		i;
	long long	power;

	i = 1;
	power = n < 0 ? -base : base;
	while ((n / power) > base)
	{
		i++;
		power *= base;
	}
	return (i);
}
