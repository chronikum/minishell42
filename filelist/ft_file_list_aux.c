#include "../includes/ft_minishell.h"

int	ft_file_count(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}
