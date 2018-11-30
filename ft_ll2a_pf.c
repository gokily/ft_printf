
#include <stdlib.h>

static int	digit_num(long long n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_ll2a_pf(long long n)
{
	long long	power;
	char	*ptr;
	size_t	i;

	power = (n < 0) ? -1 : 1;
	power = n > 9 || n < -9 ? power * 10 : power;
	while (n / power > 9)
		power *= 10;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (digit_num(n) + 1))))
		return (0);
	i = 0;
	while (power != 0)
	{
		ptr[i] = n / power + 48;
		n %= power;
		power /= 10;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
