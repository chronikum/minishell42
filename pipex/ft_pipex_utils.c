#include "../includes/ft_minishell.h"

int	ft_check_file(t_pipes *p, char *filename)
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
	p->exit_status = 1;
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

void	ft_command_not_found(t_pipes *p, char *command)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(RED_COLOR, 2);
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(RESET_COLOR, 2);
	ft_putendl_fd(command, 2);
	p->exit_status = 127;
}
