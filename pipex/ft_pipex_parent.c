/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_parent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:55:21 by olgerret          #+#    #+#             */
/*   Updated: 2021/10/08 13:54:03 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_double_dub(t_pipes *p, int out)
{
	close(p->pipe[1]);
	dup2(p->temp_fd, 0);
	dup2(out, 1);
}

void	ft_open_out(t_parent *prnt, char **argv)
{
	prnt->out = open(argv[prnt->argc_parent - 1],
			O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (prnt->out == -1)
	{
		ft_putstr_fd("Permission denied: ", 2);
		ft_putendl_fd(argv[prnt->argc_parent - 1], 2);
		exit (0);
	}
}

int	parent(t_pipes *p, t_parent *prnt, char **argv, char **envp)
{
	ft_open_out(prnt, argv);
	if (waitpid(-1, NULL, 0)
		&& check_file(argv[prnt->argc_parent - 1], 'W') != -1)
	{
		ft_double_dub(p, prnt->out);
		prnt->cmnd = ft_split(argv[prnt->argc_parent - 2], ' ');
		prnt->paths = path_finder(envp);
		prnt->i = ft_array_len(prnt->paths);
		while (prnt->i >= 0)
		{
			prnt->temp = ft_strjoin(prnt->paths[prnt->i], "/");
			prnt->full_path = ft_strjoin(prnt->temp, prnt->cmnd[0]);
			if (access(prnt->full_path, F_OK) != -1)
				execve(prnt->full_path, prnt->cmnd, envp);
			if (access(prnt->full_path, F_OK) == -1 && prnt->i == 0)
				command_not_found(argv, 'P');
			ft_custom_free(&prnt->full_path, &prnt->temp, 'S');
			prnt->i--;
		}
	}
	ft_custom_free(prnt->cmnd, prnt->paths, 'D');
	exit(0);
}
