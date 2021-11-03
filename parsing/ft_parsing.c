#include "../includes/ft_minishell.h"

/*
	Parses a single segment of a command into a linked list
	and returns the parsed linked list
	The flag is the type of redirection which should be set.
	Those are also defined in the header file
*/
t_command	*ft_parser(char *cmd, int in_flag, int out_flag)
{
	char **command_parts;
	char *main_command;
	t_command *command_struct;

	command_struct = ft_malloc(sizeof(t_command));
	command_struct->next = NULL;
	command_parts = ft_split_quote(cmd, ' '); // Todo only split if not surrounded by quotes
	if (!command_parts)
		return (NULL);
	main_command = command_parts[0];
	command_struct->command = ft_find_executable_path(main_command);
	command_struct->args = command_parts;
	command_struct->in_flag = in_flag;
	command_struct->out_flag = out_flag;
	if (DEBUG)
	{
		printf("IN FLAG: %d\n", command_struct->in_flag);
		printf("OUT FLAG: %d\n", command_struct->out_flag);
	}
	return (command_struct);
}

/*
	Determines the flag which is being used at the end of the command.
	- define PIPE	0  |
	- define OUT	1  >
	- define IN 	2  <
	- define LEFT	3  << here doc
	- define RIGHT	4  >> append
	- define BUILT	5
	- define SYS 	6
	- define STDOUT -1 last command in chain
*/

// todo: do something which makes sense
int	ft_determine_out_flag(char *command)
{
	if (ft_single_inset(command[0], "|><") != -1
	 && (ft_single_inset(command[1], "|><") == -1))
	{
		return (ft_single_inset(command[0], "|><"));
	}
	if (ft_single_inset(command[0], "<>") != -1
	 && (ft_single_inset(command[1], "<>") != -1))
	{
		return (ft_single_inset(command[1], "<>") + 3);
	}
	return (7);
}

int	ft_determine_in_flag(char *command)
{
	if (ft_single_inset(command[ft_strlen(command) - 1], "|><") != -1
	 && (ft_single_inset(command[ft_strlen(command) - 2], "|><") == -1))
	{
		return (ft_single_inset(command[ft_strlen(command) - 1], "|><"));
	}
	if (ft_single_inset(command[ft_strlen(command) - 1], "<>") != -1
	 && (ft_single_inset(command[ft_strlen(command) - 2], "<>") != -1))
	{
		return (ft_single_inset(command[ft_strlen(command) - 1], "<>") + 3);
	}
	return (-1);
}

/*
	Parses a string of commands in multiple single segments
	and creates a funky linked command list
	out of it.

	Returns the beginning of the command list.

	TODO: Actually send the right flag to ft_parser, currently we are only sending the
	index which is not quite correct!
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
		if (ft_single_inset(cmds[i], "|><") != -1) // <
		{
			while (ft_single_inset(cmds[i], "|><") != -1) // >>
				i++;
			if (!first)
				first = ft_parser(
					ft_substr(cmds, start, (i - start)),
					ft_determine_in_flag(ft_substr(cmds, start, (i - start))),
					ft_determine_out_flag(ft_substr(cmds, start, (i - start)))
				);
			else
				ft_commandaddback(&first, ft_parser(
					ft_substr(cmds, start, (i - start)),
					ft_determine_in_flag(ft_substr(cmds, start, (i - start))),
					ft_determine_out_flag(ft_substr(cmds, start, (i - start)))
				));
			start = i;
		}
		i++;
	}
	if (!first)
		first = ft_parser(cmds, -1, -1);
	else
		ft_commandaddback(&first, ft_parser(ft_substr(cmds, start, (i - start)), ft_determine_in_flag(ft_substr(cmds, start, (i - start))), ft_determine_out_flag(ft_substr(cmds, start, (i - start)))));

	return (first);
}