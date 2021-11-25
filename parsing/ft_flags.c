#include "../includes/ft_minishell.h"

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
	command->out_flag = PIPE;
	if (ft_strnstr_quotes(command->original_string, "<", ft_strlen(command->original_string)))
		command->in_flag = IN;
	if (ft_strnstr_quotes(command->original_string, "<<", ft_strlen(command->original_string)))
		ft_setup_heredoc(command);
	if (ft_strnstr_quotes(command->original_string, ">", ft_strlen(command->original_string)))
		command->out_flag = OUT;
	if (ft_strnstr_quotes(command->original_string, ">>", ft_strlen(command->original_string)))
		command->out_flag = APPEND;
}