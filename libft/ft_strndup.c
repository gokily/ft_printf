#include <stdlib.h>

char	*ft_strndup(const char *str, size_t len)
{
	size_t	i;
	char	*ret;
	
	i = 0;
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);	
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
