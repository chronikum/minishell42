#include "./includes/ft_minishell.h"

void	ft_arg_printer(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		printf("%s\n", args[i]);
		i++;
	}
}