#include "../includes/ft_minishell.h"

/*
	Parses a single segment of a command into a linked list
	and returns the parsed linked list
*/
t_command	*ft_parser(char *cmd)
{
	char **command_parts;
	char *main_command;
	t_command *command_struct;

	command_struct = malloc(sizeof(t_command));
	command_parts = ft_split_quote(cmd, ' '); // Todo only split if not surrounded by quotes
	if (!command_parts)
		return (NULL);
	main_command = command_parts[0];
	command_struct->command = ft_find_executable_path(main_command);
	command_struct->args = command_parts;
	free(command_parts);
	return (command_struct);
}

/*
	Parses a string of commands in multiple single segments
	and creates a funky linked command list
	out of it.
	
	Returns the beginning of the command list.
*/
t_command		*ft_parse_in_commands(char *cmds)
{
	int		i;
	int		start;
	t_command	*first;
	
	i = 0;
	start = 0;
	first = NULL;
	while(cmds[i])
	{
		if (ft_single_inset(cmds[i], "|><") != -1)
		{
			if (!first)
				first = ft_parser(ft_substr(cmds, start, (i - start)));
			else
				ft_commandaddback(&first, ft_parser(ft_substr(cmds, start, (i - start))));
			start = i;
		}
		i++;
	}
	if (!first)
		first = ft_parser(cmds);
	
	return (first);
}