#include "ft_gc_functions.h"

char	*ft_gc_substr(char const *s, unsigned int start, int len)
{
	char	*result;
	int	i;

	if (s == 0)
		return (0);
	result = (char *)ft_malloc((len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		result[0] = '\0';
		return (result);
	}
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
