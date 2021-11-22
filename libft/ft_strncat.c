#include "libft.h"

char	*ft_strncat(char *str1, char *str2, size_t n)
{
	int	i;
	int	j;

	i = -1;
	j = (int) ft_strlen(str1);
	while ((*(str2 + ++i)) && i < (int) n)
	{
		str1[j] = str2[i];
		j++;
	}
	str1[j] = '\0';
	return (str1);
}