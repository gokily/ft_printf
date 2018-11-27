#include <string.h>

char	*ft_strchrstr(char *str, char *elem)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (elem[j] != '\0')
		{
			if (str[i] == elem[j])
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}