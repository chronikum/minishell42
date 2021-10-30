#include "../includes/ft_minishell.h"

/*
	Parses a single segment of a command into a linked list
	and returns the parsed linked list
	The flag is the type of redirection which should be set.
	Those are also defined in the header file
*/
t_command	*ft_parser(char *cmd, int flag)
{
	char **command_parts;
	char *main_command;
	t_command *command_struct;

	command_struct = malloc(sizeof(t_command));
	command_struct->next = NULL;
	command_parts = ft_split_quote(cmd, ' '); // Todo only split if not surrounded by quotes
	if (!command_parts)
		return (NULL);
	main_command = command_parts[0];
	command_struct->command = ft_find_executable_path(main_command);
	command_struct->args = command_parts;
	command_struct->flag = flag;
	printf("FLAG: %d\n", command_struct->flag);
	free(command_parts);
	return (command_struct);
}

/*
	Determines the flag which is being used at the end of the command.
	- define PIPE 1 // |
	- define OUT 2 // >
	- define IN 3 // <
	- define LEFT 4 // << here doc
	- define RIGHT 5 // >> append
	- define BUILT 6
	- define SYS 7
	- define STDOUT -1 // last command in chain
*/
int	ft_determine_flag(char *command)
{
	if (ft_single_inset(command[ft_strlen(command) - 1], "|><") != -1
	 && (ft_single_inset(command[ft_strlen(command) - 2], "|><") == -1))
	{
		return (ft_single_inset(command[ft_strlen(command) - 1], "|><"));
	}
	if (ft_single_inset(command[ft_strlen(command) - 1], "><") != -1
	 && (ft_single_inset(command[ft_strlen(command) - 2], "><") != -1))
	{
		return (ft_single_inset(command[ft_strlen(command) - 1], "|><") + 2);
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
		if (ft_single_inset(cmds[i], "|><") != -1)
		{
			while (ft_single_inset(cmds[i], "|><") != -1)
				i++;
			if (!first)
				first = ft_parser(ft_substr(cmds, start, (i - start)), ft_determine_flag(ft_substr(cmds, start, (i - start))));
			else
				ft_commandaddback(&first, ft_parser(ft_substr(cmds, start, (i - start)), ft_determine_flag(ft_substr(cmds, start, (i - start)))));
			start = i;
		}
		i++;
	}
	if (!first)
		first = ft_parser(cmds, -1);
	else
		ft_commandaddback(&first, ft_parser(ft_substr(cmds, start, (i - start)), ft_determine_flag(ft_substr(cmds, start, (i - start)))));
	
	return (first);
}