#include "../includes/ft_minishell.h"

/*
	Creates a command from a string which is guaranteed to be a single command
	only. It contains out and infiles, quotes and spaces.
*/
t_command	*ft_cr_com(char *command_section)
{
	t_command	*command;
	char		**splitted_commands;

	command = ft_newcommand(command_section);
	printf("CREATING COMMAND SECTION: %s\n", command_section);
	if (ft_check_infile(command, command_section))
		return (command);
	splitted_commands = ft_splint(command_section);
	command->args = splitted_commands;
	if (splitted_commands)
		command->command = ft_find_executable_path(command->args[0]);
	ft_set_flags(command);
	ft_set_builtin_flag(command);
	command->files = ft_create_file_list(command_section);
	return (command);
}

/*
	Parses a string of commands in multiple single segments
	and creates a funky linked command list
	out of it.
*/
t_command	*ft_parse_in_commands(char *cmds)
{
	t_command	*list;
	int			i;
	int			qs[3];

	i = 0;
	list = NULL;
	qs[0] = 1;
	qs[1] = 1;
	qs[2] = 0;
	while (cmds[i])
	{
		if (qs[0] && ft_single_inset(
				cmds[i], "|") != -1 && qs[1] && qs[0])
		{
			ft_commandaddback(&list, ft_cr_com(
					ft_gc_substr(cmds, qs[2], i - qs[2])));
			qs[2] = i;
		}
		ft_single_double_quote_handler(cmds, &i, &qs[0], &qs[1]);
	}
	ft_commandaddback(&list, ft_cr_com(ft_gc_substr(cmds, qs[2], i - qs[2])));
	if (ft_get_last_command(list)->out_flag == 0)
		ft_get_last_command(list)->out_flag = -1;
	ft_command_debug(list);
	return (list);
}
