#include "../includes/ft_minishell.h"

int	check_file(char *filename, char RW)
{
	if (RW == 'W')
	{
		if (access(filename, W_OK) == -1)
		{
			ft_putstr_fd("permission denied ", 2);
			ft_putendl_fd(filename, 2);
			return (-1);
		}
	}
	else if (RW == 'R')
	{
		if (access(filename, F_OK) == -1)
		{
			ft_putstr_fd("no such file or directory: ", 2);
			ft_putendl_fd(filename, 2);
			return (-1);
		}
		else if (access(filename, R_OK) == -1)
		{
			ft_putstr_fd("permission denied ", 2);
			ft_putendl_fd(filename, 2);
			return (-1);
		}
	}
	return (0);
}

int	ft_array_len(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
		i++;
	return (i);
}

void	command_not_found(char *command)
{
	ft_putstr_fd(RED_COLOR, 2);
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(RESET_COLOR, 2);
	ft_putendl_fd(command, 2);
}
