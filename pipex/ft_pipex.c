/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:20:50 by olgerret          #+#    #+#             */
/*   Updated: 2021/10/08 13:54:52 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	child(t_pipes *p, char **argv, char **envp)
{
	t_child	var;

	dup2(p->temp_fd, 0);
	close(p->pipe[0]);
	dup2(p->pipe[1], 1);
	var.cmnd = ft_split(argv[p->cmnd_count], ' ');
	var.paths = path_finder(envp);
	var.i = ft_array_len(var.paths);
	while (var.i >= 0)
	{
		var.temp = ft_strjoin(var.paths[var.i], "/");
		var.full_path = ft_strjoin(var.temp, var.cmnd[0]);
		if (access(var.full_path, F_OK) != -1)
			execve(var.full_path, var.cmnd, envp);
		if (access(var.full_path, F_OK) == -1 && var.i == 0)
			command_not_found(argv, 'C');
		ft_custom_free(&var.full_path, &var.temp, 'S');
		var.i--;
	}
	ft_custom_free(var.cmnd, var.paths, 'D');
	exit(0);
}

void	cutlery_close(t_pipes *p, t_parent *prnt)
{
	close(p->temp_fd);
	close(p->in);
	close(prnt->out);
}

void	cutlery_dup(t_pipes *p)
{
	close(p->pipe[1]);
	close(p->temp_fd);
	dup2(p->pipe[0], p->temp_fd);
	close(p->pipe[0]);
}

void	cutlery(t_pipes *p, t_parent *prnt, char **argv, char **envp)
{
	pid_t	pid;
	int		processes;

	processes = prnt->argc_process - 4;
	while (processes > 0)
	{
		if (pipe(p->pipe) == -1)
		{
			perror("Error");
			exit(0);
		}
		p->cmnd_count++;
		pid = fork();
		if (pid == -1)
			exit (0);
		if (pid == 0)
			child(p, argv, envp);
		wait(0);
		cutlery_dup(p);
		processes -= 1;
	}
	if (processes == 0)
		parent(p, prnt, argv, envp);
	cutlery_close(p, prnt);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipes		p;
	t_parent	prnt;

	prnt.argc_process = argc;
	prnt.argc_parent = argc;
	p.in = 0;
	p.cmnd_count = 1;
	check_file(argv[1], 'R');
	p.in = open(argv[1], O_RDONLY);
	if (p.in == -1)
	{
		p.temp_fd = 5;
		p.cmnd_count++;
		prnt.argc_process--;
	}
	else
		p.temp_fd = p.in;
	cutlery(&p, &prnt, argv, envp);
	return (0);
}
