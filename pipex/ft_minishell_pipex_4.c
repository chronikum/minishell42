/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_pipex_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:30:40 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/08 09:19:29 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

int	g_global;

void	ft_pipe_pre_dup(t_pipes *p)
{
	dup2(p->pipe[1], 1);
	if (p->pipe[1])
		close(p->pipe[1]);
}

void	ft_outfile_dup(t_pipes *p)
{
	dup2(p->out, 1);
}

void	ft_stdout_dup(t_pipes *p)
{
	dup2(p->stout, 1);
}

void	ft_execute(t_command *commands, t_envlist *envp)
{
	t_child	*c;

	c = ft_malloc(sizeof(t_child));
	if (commands->args[0][0] == '/')
		c->full_path = commands->original_string;
	else
		c->full_path = ft_find_executable_path(commands->args[0]);
	if (access(c->full_path, F_OK) != -1)
		execve(c->full_path, commands->args, envp->envp);
	if (access(c->full_path, F_OK) == -1 && c->i == 0)
	{
		ft_command_not_found(commands->original_string);
		exit(127);
	}
}

void	ft_system_command(t_pipes *p, t_command *commands, t_envlist *envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid == 0)
	{
		if (p->pipe[0])
			close(p->pipe[0]);
		ft_execute(commands, envp);
	}
	if (pid != 0)
	{
		if (p->pipe[1])
			close(p->pipe[1]);
		wait(&status);
		if (WIFEXITED(status))
			ft_set_most_recent_exit_code(WEXITSTATUS(status), 1);
	}
}
