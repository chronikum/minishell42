#include "../includes/ft_minishell.h"

/*
	Adds the infile to the command struct
*/
static void	ft_set_infile(t_command	*command)
{
	char *file_name;
	
	file_name = ft_gc_strtrim(ft_get_cmd_filename(command, command->original_string), "<");
	command->in_flag = IN;
	command->out_flag = IN;
	command->files = ft_new_file(file_name, file_name, 0, 0);
	printf("SETTING INFILE!\n");
}

/*
	Sets the here doc indicator and adds the delimiter
*/
static void	ft_setup_heredoc(t_command	*command)
{
	command->in_flag = HERE_DOC;
	ft_set_heredoc(command, command->original_string);
}

/*
	Set the flags which 
*/
void	ft_set_flags(t_command *command)
{
	command->out_flag = PIPE;
	if (ft_strnstr_nowhere_quotes(command->original_string, "<<",
			ft_strlen(command->original_string)))
		ft_setup_heredoc(command);
	else if (ft_strnstr_nowhere_quotes(
			command->original_string, "<",
			ft_strlen(command->original_string)))
		ft_set_infile(command);
	else if (ft_strnstr_nowhere_quotes(command->original_string, ">",
			ft_strlen(command->original_string)))
		command->out_flag = OUT;
	else if (ft_strnstr_nowhere_quotes(command->original_string, ">>",
			ft_strlen(command->original_string)))
		command->out_flag = APPEND;
}
