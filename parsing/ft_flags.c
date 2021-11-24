#include "../includes/ft_minishell.h"

/*
	Set the flags which 
*/
void	ft_set_flags(t_command *command)
{
	if (ft_strchr(command->original_string, '<') || ft_strchr(command->original_string, '>'))
		command->out_flag = 1;
	else
		command->out_flag = 0;
}