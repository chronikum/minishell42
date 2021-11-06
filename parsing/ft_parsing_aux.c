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
		if (!cmd[i] && i == 0)
			return (-1);
		if (!cmd[i] && i != 0)
			return (i);
		if (cmd[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
	Returns the length until it meets the a character specified
	in the set or a null terminator.
	Returns -1 if none of those is being found.
*/
int	ft_strlen_set(char *cmd, char *set)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!cmd[i] && i == 0)
			return (-1);
		if (!cmd[i] && i != 0)
			return (i);
		if (ft_single_inset(cmd[i], set) != -1 && i != 0)
			return (i);
		i++;
	}
	return (-1);
}