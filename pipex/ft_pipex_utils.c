#include "../includes/ft_minishell.h"

int	ft_check_file(char *filename)
{
	if (access(filename, F_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(&filename[2], 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (-1);
	}
	else if (access(filename, R_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(&filename[2], 2);
		ft_putendl_fd(": Permission denied", 2);
		return (-1);
	}
	ft_set_most_recent_exit_code(1, 1);
	return (0);
}

int	ft_array_len(char **argv)
{
	int	i;

	i = 1;
	if (argv)
	{
		while (argv[i] != NULL)
			i++;
		return (i);
	}
	return (0);
}

void	ft_command_not_found(char *command)
{
	ft_putstr_fd("urgent: ", 2);
	ft_putstr_fd(RED_COLOR, 2);
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(RESET_COLOR, 2);
	ft_putendl_fd(ft_gc_strtrim(command, "\""), 2);
	ft_set_most_recent_exit_code(127, 1);
}
