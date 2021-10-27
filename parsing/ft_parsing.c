#include "../includes/ft_minishell.h"

t_command	*ft_parser(char *cmd)
{
	char **command_parts;
	char *main_command;
	t_command *command_struct;

	command_struct = malloc(sizeof(t_command));
	command_parts = ft_split(cmd, ' '); // Todo only split if not surrounded by quotes
	main_command = command_parts[0];
	if (ft_check_command(main_command)) // check if command even exists
	{

	}


	return (command_struct);
}