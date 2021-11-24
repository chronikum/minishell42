#include "../includes/ft_minishell.h"

/*
	Set the flags which 
*/
void	ft_set_flags(t_command *command)
{
	command->out_flag = PIPE;
	if (ft_strnstr(command->original_string, "<", ft_strlen(command->original_string)))
		command->in_flag = IN;
	if (ft_strnstr(command->original_string, "<<", ft_strlen(command->original_string)))
		command->in_flag = HERE_DOC;
	if (ft_strnstr(command->original_string, ">", ft_strlen(command->original_string)))
		command->out_flag = OUT;
	if (ft_strnstr(command->original_string, ">>", ft_strlen(command->original_string)))
		command->out_flag = APPEND;
}