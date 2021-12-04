#include "../includes/ft_minishell.h"

/*
	Returns append or out indicator
*/
int	ft_append_or_out(t_command *command)
{
	int append;
	int out;
	
	command->out_flag = OUT;
	append = ft_strnstr_now_quotes_pos(command->original_string, ">>",
			ft_strlen(command->original_string));
	out = ft_strnstr_now_quotes_pos(command->original_string, ">",
			ft_strlen(command->original_string));
	if (append == out && (out != -1))
		command->out_flag = APPEND;
	if (out > append)
		command->out_flag = OUT;
	if (out < append)
		command->out_flag = APPEND;
	return (command->out_flag);
}