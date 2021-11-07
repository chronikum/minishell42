#include "../includes/ft_minishell.h"


// > >> after that comes a filename which is being supplied to the struct BEFORE the sep

void	ft_assign_file_name_to_path(t_command *command, char *file_name)
{
	command->file = NULL;
	if (file_name)
	{
		command->file = ft_strjoin("./", ft_strtrim(file_name, " "));
	}
}

/*
	Checks if the command is a builtin command
*/
int	ft_check_builtin(char *command)
{
	if (ft_spongebob_strncmp(command, "pwd", ft_strlen("pwd")) == 0)
		return (1);
	else if (ft_spongebob_strncmp(command, "exit", ft_strlen("exit")) == 0)
		return (1);
	else if (ft_spongebob_strncmp(command, "env", ft_strlen("env")) == 0)
		return (1);
	else if (ft_spongebob_strncmp(command, "echo", ft_strlen("echo")) == 0)
		return (1);
	else if (ft_spongebob_strncmp(command, "cd", ft_strlen("cd")) == 0)
		return (1);
	else if (ft_spongebob_strncmp(command, "export", ft_strlen("export")) == 0)
		return (1);
	return (0);
}


/*
	Sets the buildin sys flag to 5 or 6
*/
void	ft_set_builtin_flag(t_command *command)
{
	char *main_command;

	main_command = command->args[0];
	if (ft_check_builtin(main_command))
		command->builtin_sys_flag = BUILT_IN;
	else if (ft_find_executable_path(main_command))
		command->builtin_sys_flag = SYS;
	else
		command->builtin_sys_flag = SYS;
}

/*
	Parses a single segment of a command into a linked list
	and returns the parsed linked list
	The flag is the type of redirection which should be set.
	Those are also defined in the header file
*/
t_command	*ft_parser(char *cmd, int in_flag, int out_flag, char *file_name)
{
	char **command_parts;
	char *main_command;
	t_command *command_struct;

	command_struct = ft_malloc(sizeof(t_command));
	command_struct->next = NULL;
	command_parts = ft_splint(cmd); // Todo only split if not surrounded by quotes
	if (!command_parts)
		return (NULL);
	main_command = command_parts[0];
	command_struct->original_string = cmd;
	command_struct->command = ft_find_executable_path(main_command);
	command_struct->args = command_parts;
	if (in_flag == 2) // super important to remove this later @DEBUG
		command_struct->builtin_sys_flag = 6;
	else
		ft_set_builtin_flag(command_struct); // TODO: this needs to be adjusted: this set determined by being a system or a built_in function
	command_struct->in_flag = in_flag;
	command_struct->out_flag = out_flag;
	ft_assign_file_name_to_path(command_struct, file_name);
	if (DEBUG)
	{
		printf("%sSECTION     %s\n", BACKGROUND_BLUE, RESET_COLOR);
		printf("	Command: 			%s\n", command_struct->command);
		printf("	Full String: 			%s\n", ft_strtrim(command_struct->original_string, "<>| "));
		ft_arg_printer(command_struct->args);
		if (command_struct->file)
		{
			printf("FILE: 				%s|\n", command_struct->file);
			printf("FILE NAME LENGTH: 	%lu\n", ft_strlen(command_struct->file)); /// as we know the file name changes in length occassionally
		}
		printf("	IN FLAG: 			%d	%s\n", command_struct->in_flag, ft_translate_flags(command_struct->in_flag));
		printf("	OUT FLAG: 			%d	%s\n", command_struct->out_flag, ft_translate_flags(command_struct->out_flag));
		printf("	BUILT_SYS:			%d	%s\n", command_struct->builtin_sys_flag, ft_translate_flags(command_struct->builtin_sys_flag));
		printf("%sSECTION END %s\n", BACKGROUND_BLUE, RESET_COLOR);
	}
	return (command_struct);
}

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
	return (-1);
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
	Skips white spaces
*/
void	ft_skip_whitespaces(char *cmd, int *i)
{
	while (cmd[(*i)] == ' ')
		(*i)++;
}

/*
	Adds an outfile to the given command linked list.
	Will use the next argument in the list instead.
	Will look for the filename after the > or >> indicator
	and trim the string fromm whitespaces.
	Then it will set the result as the command->file.
	It will take the iterator i to jump to the end of the filename to
	not print out too many arguments later on
*/
t_command	*ft_add_outfile_to_commabeur(t_command *first, char *cmds, int start, int *i)
{

	char *file_name = ft_get_cmd_filename(cmds, i);
	while (cmds[(*i)] == ' ' && cmds[(*i)])
		(*i)++;
	return (ft_commandaddback(&first, ft_parser(
			ft_substr(cmds, start, ((*i) - start)),
			ft_determine_out_flag(ft_substr(cmds, start, ((*i) - start))),
			1,
			file_name
	)));
}



/*
	Gets called when a quote is being seen. Toggles a int (pointer)
*/
static void	ft_toggle_quote(int *quote_toggle)
{
	if ((*quote_toggle))
		(*quote_toggle) = 0;
	else
		(*quote_toggle) = 1;
}

/*
	Increases counter by one and toggles quote counter if it encounters one
*/
static void	ft_increase_i_quote_handler(char *cmd, int *i, int *quote)
{
	if (cmd[(*i)] == '"')
		ft_toggle_quote(quote);
	(*i)++;
}

/*
	Parses a string of commands in multiple single segments
	and creates a funky linked command list
	out of it.

	Returns the beginning of the command list.
	Also handles quotes in general by toggling a int value.
	The function

	TODO: Actually send the right flag to ft_parser, currently we are only sending the
	index which is not quite correct!
*/
t_command		*ft_parse_in_commands(char *cmds)
{
	int		i;
	int		start;
	t_command	*first;
	int	quotes_closed;
	int	skip;

	skip = 0;
	i = 0;
	start = 0;
	first = NULL;
	quotes_closed = 1;
	if (cmds[0] == '<')
	{
		first = ft_parser(
			ft_substr(cmds, ft_strlen_set(cmds, " "), ft_strlen_set(cmds, "|>")),
			2,
			ft_determine_out_flag(ft_substr(cmds, start, (i - start))),
			ft_strtrim(ft_get_cmd_filename(cmds, &i), "<")
		);
		i += ft_strlen_set(cmds, " |>");
		start = i;
		skip = 1;
	}

	while(cmds[i])
	{
		// increases i until it finds one of the seperators and only if the quotes are closed
		// problem: only gets entered if there is atleast one seperator. won't enter if there is none.
		if (ft_single_inset(cmds[i], "|><") != -1 && quotes_closed)
		{
			// then we skip the seperators
			// which we just saw to not get in an infinite while loop.
			while (ft_single_inset(cmds[i], "|><") != -1 && quotes_closed)
				ft_increase_i_quote_handler(cmds, &i, &quotes_closed);
			// then we check if we already added a seperator to the list (if yes, we can ignore this safely.)
			// this checks also for everything which is NOT an OUT file. It would thereotically match
			// the infile too
			if (!first && ft_determine_in_flag(ft_substr(cmds, start, (i - start))) != 1 && quotes_closed)
			{
				first = ft_parser(
					ft_substr(cmds, start, (i - start)),
					ft_determine_out_flag(ft_substr(cmds, start, (i - start))),
					ft_determine_in_flag(ft_substr(cmds, start, (i - start))),
					NULL
				);
			}
			// check if is output file
			else if ((ft_determine_in_flag(ft_substr(cmds, start, (i - start))) == 1
				|| ft_determine_in_flag(ft_substr(cmds, start, (i - start))) == 4) && quotes_closed)
			{
				first = ft_add_outfile_to_commabeur(first, cmds, start, &i);
			}
			// check if it is pipe
			else if (ft_determine_in_flag(ft_substr(cmds, start, (i - start))) == 0 && quotes_closed)
			{
				ft_commandaddback(&first, ft_parser(
					ft_substr(cmds, start, (i - start)),
					ft_determine_out_flag(ft_substr(cmds, start, (i - start))),
					ft_determine_in_flag(ft_substr(cmds, start, (i - start))),
					NULL
				));
			}
			start = i;
		}
		ft_increase_i_quote_handler(cmds, &i, &quotes_closed);
	}

	// we need to get the commands after
	// <infile cat | HERE
	// right now they are just being skipped
	// it should not be like that.

	// idea is to implement the single command check in the while loop
	// somehow so we can reset the skip flag
	if (!first)
		first = ft_parser(cmds, -1, -1, NULL);
	else if (skip == 0)
		ft_commandaddback(&first, ft_parser(ft_substr(cmds, start, (i - start)), ft_determine_in_flag(ft_substr(cmds, start, (i - start))), ft_determine_out_flag(ft_substr(cmds, start, (i - start))), NULL));

	return (first);
}