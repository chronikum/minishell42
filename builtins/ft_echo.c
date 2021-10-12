#include "../includes/ft_minishell.h"

/**
 * Counts how many unescaped quotes are in a character sequence
 */
int	ft_count_quotes(char *characters)
{
	int counter;
	int counted_characters;
	
	counter = 0;
	counted_characters = 0;
	while (characters[counter])
	{
		if (characters[counter] == '"' && characters[counter - 1] != '\\')
			counted_characters++;
		counter++;
	}
	return (counted_characters);
}

/**
 * Returns one if was successful.
 * Checks for escaping quotes and quotes at and or beginning or
 * no quotes at all
 * TODO: Check forbidden signs like double exclamation mark
 * TODO: Clean the text_to_echo up so no unescaped quotes remain in output
 * 
 */
int	ft_check_quotes(char *text_to_echo)
{
	if (ft_count_quotes(text_to_echo) % 2 == 0)
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
		ft_putstr_fd("Error\n", 2);
	return (0);
}