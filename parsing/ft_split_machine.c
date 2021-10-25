#include "../includes/ft_minishell.h"

char ***ft_split_machine(char *str, char dlmtr)
{	
	int i;
	char **result;
	char ***threedim;

	result = ft_split(str, dlmtr);
	threedim = malloc(50000);
	if (threedim == NULL)
		return (NULL);
	i = 0;
	while (result[i] != NULL)
		i++;
	threedim[i] = NULL;
	while (i > 0)
	{
		i--;
		threedim[i] = ft_split(result[i], ' ');
	}
	return (threedim);
}
