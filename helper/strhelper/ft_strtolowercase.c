#include "../ft_gc_functions.h"
#include "../../libft/libft.h"

char *ft_strtolowercase(char *str)
{
	int	i;
	char *temp;

	i = 0;
	temp = ft_gc_strdup(str);
	while (temp[i])
	{
		temp[i] = ft_tolower(temp[i]);
		i++;
	}
	return temp;
}