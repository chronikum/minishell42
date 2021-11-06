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
	if (ft_strncmp(command, "pwd", ft_strlen("pwd")) == 0)
		return (1);
	else if (ft_strncmp(command, "exit", ft_strlen("exit")) == 0)
		return (1);
	else if (ft_strncmp(command, "env", ft_strlen("env")) == 0)
		return (1);
	else if (ft_strncmp(command, "echo", ft_strlen("echo")) == 0)
		return (1);
	else if (ft_strncmp(command, "cd", ft_strlen("cd")) == 0)
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
	if (ft_find_executable_path(main_command))
		command->builtin_sys_flag = 6;
	else  if (ft_check_builtin(main_command))
		command->builtin_sys_flag = 5;
	else
		command->builtin_sys_flag = 7;
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
	command_parts = ft_split_quote(cmd, ' '); // Todo only split if not surrounded by quotes
	if (!command_parts)
		return (NULL);
	main_command = command_parts[0];
	command_struct->command = ft_find_executable_path(main_command);
	command_struct->args = command_parts;
	if (in_flag == 2) // super important to remove this later @DEBUG
		command_struct->builtin_sys_flag = 7;
	else
		ft_set_builtin_flag(command_struct); // TODO: this needs to be adjusted: this set determined by being a system or a built_in function
	command_struct->in_flag = in_flag;
	command_struct->out_flag = out_flag;
	ft_assign_file_name_to_path(command_struct, file_name);
	if (DEBUG)
	{
		printf("----- SECTION -----\n");
		printf("Command: 			%s\n", command_struct->command);
		ft_arg_printer(command_struct->args);
		if (command_struct->file)
		{
			printf("FILE: 				%s|\n", command_struct->file);
			printf("FILE NAME LENGTH: 	%lu\n", ft_strlen(command_struct->file)); /// as we know the file name changes in length occassionally
		}
		printf("IN FLAG: 			%d\n", command_struct->in_flag);
		printf("OUT FLAG: 			%d\n", command_struct->out_flag);
		printf("BUILT_SYS:			%d\n", command_struct->builtin_sys_flag);
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
	Gets called when a quote is being seen. Toggles a int (pointer)
*/
void	ft_toggle_quote(int *quote_toggle)
{
	if ((*quote_toggle))
		(*quote_toggle) = 0;
	else
		(*quote_toggle) = 1;
}

///*
//	Parses a string of commands in multiple single segments
//	and creates a funky linked command list
//	out of it.

//	Returns the beginning of the command list.

//	TODO: Actually send the right flag to ft_parser, currently we are only sending the
//	index which is not quite correct!
//*/
//t_command		*ft_parse_in_commands(char *cmds)
//{
//	int	i;
//	int	start;
//	t_command	*first;
//	int quotes_closed;

//	i = 0;
//	start = 0;
//	quotes_closed = 1;
//	first = NULL;
//	while (cmds[i]) // go through all characters of the command
//	{
//		if (cmds[i] == '"')
//			ft_toggle_quote(&quotes_closed);
//		ft_skip_whitespaces(&cmds[i], &i);
//		printf("CURRENT; %c \n", cmds[i]);
//		if (cmds[i] == '>' && (quotes_closed == 1))
//		{
//			//printf("FILE NAME: %s \n", ft_substr(cmds, i, ft_strlenc(&cmds[i], ' ')));
//			printf("Length: %d \n", ft_strlenc(&cmds[i], ' '));
//			ft_commandaddback(&first,
//				ft_parser(
//				cmds,
//				ft_determine_out_flag(ft_substr(cmds, start, (i - start))),
//				ft_determine_in_flag(ft_substr(cmds, start, (i - start))),
//				ft_substr(cmds, (i), ft_strlenc(&cmds[start], ' '))
//			));
//		}
//		start = i;
//		i++;
//	}

//	return (first);
//}

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
	while (cmds[(*i)] != ' ' && cmds[(*i)])
		(*i)++;
	return (ft_commandaddback(&first, ft_parser(
			ft_substr(cmds, start, ((*i) - start)),
			ft_determine_out_flag(ft_substr(cmds, start, ((*i) - start))),
			1,
			file_name
	)));
}


/*
	Increases counter by one and toggles quote counter if it encounters one
*/
void	ft_increase_i_quote_handler(char *cmd, int *i, int *quote)
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
	char *file_name;
	int	quotes_closed;

	i = 0;
	start = 0;
	first = NULL;
	quotes_closed = 1;
	if (cmds[0] == '<')
	{
		while (cmds[i] != ' ' && cmds[i] && quotes_closed)
			ft_increase_i_quote_handler(cmds, &i, &quotes_closed);
		file_name = ft_get_cmd_filename(cmds, &i);
		first = ft_parser(
					ft_substr(cmds, start, (i - start)),
					2,
					7,
					file_name
				);
		start = i;
	}
	while(cmds[i])
	{
		if (ft_single_inset(cmds[i], "|><") != -1 && quotes_closed) // <
		{
			while (ft_single_inset(cmds[i], "|><") != -1 && quotes_closed) // >>
				ft_increase_i_quote_handler(cmds, &i, &quotes_closed);
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
			else
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

	if (!first)
		first = ft_parser(cmds, -1, -1, NULL);
	else
		ft_commandaddback(&first, ft_parser(ft_substr(cmds, start, (i - start)), ft_determine_in_flag(ft_substr(cmds, start, (i - start))), ft_determine_out_flag(ft_substr(cmds, start, (i - start))), NULL));

	return (first);
}