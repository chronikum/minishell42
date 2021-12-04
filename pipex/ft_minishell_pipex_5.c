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
	while (argv[i] != NULL)
		i++;
	return (i);
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

void	ft_close(t_pipes *p, t_command *commands)
{
	if (commands->out_flag != PIPE)
	{
		if (p->temp_fd)
			close(p->temp_fd);
		if (p->stout)
			close(p->stout);
	}
	if (p->in)
		close(p->in);
	if (p->out)
		close(p->out);
	if (p->pipe[0])
		close(p->pipe[0]);
	if (p->pipe[1])
		close(p->pipe[1]);
}

void	ft_pipe_after_dup(t_pipes *p)
{
	if (p->pipe[1])
		close(p->pipe[1]);
	if (p->temp_fd)
		close(p->temp_fd);
	dup2(p->pipe[0], p->temp_fd);
	if (p->pipe[0])
		close(p->pipe[0]);
}
