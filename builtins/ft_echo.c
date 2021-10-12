#include "../includes/ft_minishell.h"

/**
 * Returns one if was successful.
 * Checks for escaping quotes and quotes at and or beginning or
 * no quotes at all
 * TODO: Check forbidden signs like double exclamation mark
 * TODO: Actual checking for quotes
 */
int	ft_check_quotes(char *text_to_echo)
{
	if (!ft_strchr(text_to_echo, '"'))
		return (1);
	return (0);
}

/**
 * Returns one on success
 * Takes n parameter
 */
int	ft_echo(char *cmd, int n)
{
	char *command_split;
	
	command_split = ft_substr(cmd, 5, ft_strlen(cmd) - 5);
	if (ft_check_quotes(command_split) && !n)
	{
		ft_putendl_fd(command_split, 1);
		return (1);
	}
	else if (ft_check_quotes(command_split) && n)
	{
		ft_putstr_fd(command_split, 1);
		return (1);
	}
	else
		ft_putstr_fd("Parsing error", 2);
	return (0);
}