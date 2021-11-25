#include "../includes/ft_minishell.h"

/*
	Inserts the exit code
*/
char	*ft_insert_exit_code(char *command)
{
	if (ft_strnstr_quotes(command, "$?", ft_strlen(command)))
	{
		if (DEBUG)
			printf("DETECTED EXIT CODE!");
	}
	return (command);
}