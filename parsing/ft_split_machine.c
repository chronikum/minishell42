#include "../includes/ft_minishell.h"

char ***ft_split_machine(char *str, char dlmtr)
{	
	int i;
	char **two_dim;
	char ***three_dim;

	two_dim = ft_split(str, dlmtr);
	three_dim = malloc(50000);
	if (three_dim == NULL)
		return (NULL);
	i = 0;
	while (two_dim[i] != NULL)
		i++;
	three_dim[i] = NULL;
	while (i > 0)
	{
		i--;
		three_dim[i] = ft_split(two_dim[i], ' ');
	}
	ft_double_free(two_dim);
	return (three_dim);
}
