#include "../includes/ft_minishell.h"

/*
	Returns the length until it meets the character specified
	or a null terminator.
	Returns -1 if none of both is being found.
*/
int	ft_strlenc(char *cmd, char c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!cmd[i])
			return (-1);
		if (cmd[i] == c)
			return (i);
		i++;
	}
	return (-1);
}