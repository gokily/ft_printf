#include <stdlib.h>

char		*ft_ull2a(unsigned long long n)
{
	unsigned long long	power;
	char	*ptr;
	size_t	i;

	power = 1;
	i = 1;
	while (n / power > 9)
	{
		i++;
		power *= 10;
	}
	if (!(ptr = (char *)malloc(sizeof(char) * (i + 1))))
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