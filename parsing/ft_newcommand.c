#include "../includes/ft_minishell.h"

/*
	Initiates a new command with ONLY
	the command value filled.
*/
t_command	*ft_newcommand(char *command)
{
	t_command	*result;

	result = (t_command *)malloc(sizeof(t_command));
	if (result == 0)
		return (0);
	result->command = command;
	result->next = NULL;
	return (result);
}
