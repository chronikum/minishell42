#include "../includes/ft_minishell.h"

/*
	Adds the infile to the command struct
*/
static void ft_set_infile(t_command *command)
{
	command->in_flag = IN;
}

/*
	Sets the here doc indicator and adds the delimiter
*/
static void ft_setup_heredoc(t_command *command)
{
	command->in_flag = HERE_DOC;
	ft_set_heredoc(command, command->original_string);
}

/*
	Set the flags which 
*/
void	ft_set_flags(t_command *command)
{
	printf("LOOKING AT THE STRING: %s \n", command->original_string);
	command->out_flag = PIPE;
	if (ft_strnstr_nowhere_quotes(command->original_string, "<<", ft_strlen(command->original_string)))
		ft_setup_heredoc(command);
	else if (ft_strnstr_nowhere_quotes(command->original_string, "<", ft_strlen(command->original_string)))
		ft_set_infile(command);
	if (ft_strnstr_nowhere_quotes(command->original_string, ">", ft_strlen(command->original_string)))
		command->out_flag = OUT;
	if (ft_strnstr_nowhere_quotes(command->original_string, ">>", ft_strlen(command->original_string)))
		command->out_flag = APPEND;
}