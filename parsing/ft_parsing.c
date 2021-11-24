#include "../includes/ft_minishell.h"


void	ft_command_debug(t_command *start)
{
	t_command *command_struct;
	
	command_struct = start;
	
	while (command_struct)
	{
		if (DEBUG)
		{
			printf("%sSECTION     %s\n", BACKGROUND_BLUE, RESET_COLOR);
			printf("	Command: 			%s\n", command_struct->command);
			printf("	original_string: 		%s\n", ft_gc_strtrim(command_struct->original_string, "<>| "));
			ft_arg_printer(command_struct->args);
			if (command_struct->file)
			{
				printf("	file: 				%s|\n", command_struct->file);
				printf("	FILE PATH LENGTH : 		%lu\n", ft_strlen(command_struct->file)); /// as we know the file name changes in length occassionally
			}
			printf("	files: 			\n");
			ft_print_files(command_struct->files);
			printf("	in_flag: 			%d	%s\n", command_struct->in_flag, ft_translate_flags(command_struct->in_flag));
			printf("	out_flag: 			%d	%s\n", command_struct->out_flag, ft_translate_flags(command_struct->out_flag));
			printf("	builtin_sys_flag:		%d	%s\n", command_struct->builtin_sys_flag, ft_translate_flags(command_struct->builtin_sys_flag));
			printf("%sSECTION END %s\n", BACKGROUND_BLUE, RESET_COLOR);
		}
		command_struct = command_struct->next;
	}
}

/*
	Creates a command from a string which is guaranteed to be a single command
	only. It contains out and infiles, quotes and spaces.
*/
t_command	*ft_create_new_command(char *command_section)
{
	t_command	*command;
	
	command = ft_newcommand(command_section);
	command->args = ft_splint(command_section);
	ft_set_builtin_flag(command);
	ft_set_flags(command);
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
	int			quotes_closed;
	int			start;
	
	i = 0;
	list = NULL;
	quotes_closed = 1;
	start = 0;
	while (cmds[i])
	{
		// New command section.
		// i is now at the end of the last command.
		if (quotes_closed && ft_single_inset(cmds[i], "|") != -1)
		{
			// Append to the list or create if does not exist
			ft_commandaddback(
				&list,
				ft_create_new_command(ft_gc_substr(cmds, start, i - start))
			);
			start++;
			start = i;
		}
		ft_increase_i_quote_handler(cmds, &i, &quotes_closed);
	}
	// Adds the last or the first argument
	ft_commandaddback(
		&list,
		ft_create_new_command(ft_gc_substr(cmds, start, i - start))
	);
	if (ft_get_last_command(list)->out_flag == 0)
		ft_get_last_command(list)->out_flag = -1;
		
	ft_command_debug(list);
	return (list);
}
