#include "../includes/ft_minishell.h"

void	ft_command_debug(t_command *start)
{
	t_command	*command_struct;

	command_struct = start;
	while (command_struct)
	{
		if (DEBUG)
		{
			printf("%sSECTION     %s\n", BACKGROUND_BLUE, RESET_COLOR);
			printf("	Command: 			%s\n", command_struct->command);
			printf("	original_string: 		%s\n",
				ft_gc_strtrim(command_struct->original_string, "<>| "));
			printf("	delimiter: 				%s\n",
				command_struct->delimiter);
			ft_arg_printer(command_struct->args);
			if (command_struct->file)
			{
				printf("	file: 				%s|\n", command_struct->file);
				printf("	FILE PATH LENGTH : 		%lu\n",
					ft_strlen(command_struct->file));
			}
			printf("	files: 			\n");
			ft_print_files(command_struct->files);
			printf("	in_flag: 			%d	%s\n",
				command_struct->in_flag,
				ft_translate_flags(command_struct->in_flag));
			printf("	out_flag: 			%d	%s\n",
				command_struct->out_flag,
				ft_translate_flags(command_struct->out_flag));
			printf("	builtin_sys_flag:		%d	%s\n",
				command_struct->builtin_sys_flag,
				ft_translate_flags(command_struct->builtin_sys_flag));
			printf("%sSECTION END %s\n", BACKGROUND_BLUE, RESET_COLOR);
		}
		command_struct = command_struct->next;
	}
}

/*
	Creates a command from a string which is guaranteed to be a single command
	only. It contains out and infiles, quotes and spaces.
*/
t_command	*ft_cr_com(char *command_section)
{
	t_command	*command;
	char		**splitted_commands;

	command = ft_newcommand(command_section);
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
