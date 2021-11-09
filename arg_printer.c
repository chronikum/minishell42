#include "./includes/ft_minishell.h"

/*
	Prints all the elements in a given char
	array array
*/
void	ft_arg_printer(char **args)
{
	int	i;
	int	counter;
	int	args_count;

	i = 0;
	counter = 0;
	args_count = ft_array_len(args);
	while (args[i])
	{
		printf("	%s( ARG %d/%d )%s			|%s|\n", YELLOW_COLOR, (counter + 1), args_count, RESET_COLOR, args[i]);
		i++;
		counter++;
	}
}
