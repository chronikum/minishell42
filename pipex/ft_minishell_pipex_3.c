/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_pipex_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:30:31 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 17:30:32 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

int	g_global;

void	ft_init_dup(t_pipes *p)
{
	dup2(p->temp_fd, 0);
}

void	ft_open_error(t_pipes *p, t_command *commands)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(commands->file, 2);
	ft_putendl_fd(": Permission denied", 2);
	ft_set_most_recent_exit_code(1, 1);
	commands->builtin_sys_flag = 7;
	close(p->out);
}

void	ft_open_outfile(t_pipes *p, t_command *commands)
{	
	t_files	*temp;

	temp = commands->files;
	if (commands->out_flag == OUT)
		p->out = open(temp->file_name,
				 O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (commands->out_flag == APPEND)
		p->out = open(temp->file_name,
				 O_RDWR | O_CREAT | O_APPEND, 0777);
	if (p->out == -1)
		ft_open_error(p, commands);
}

void	ft_open_infile(t_pipes *p, t_command *commands)
{
	t_files	*temp;

	temp = commands->files;
	ft_check_file(temp->file_name);
	p->temp_fd = open(temp->file_name, O_RDONLY);
	if (p->temp_fd == -1)
	{
		commands->builtin_sys_flag = 7;
		p->temp_fd = 5;
	}
}

void	ft_pipe(t_pipes *p)
{
	if (pipe(p->pipe) == -1)
	{
		perror("Error");
		ft_set_most_recent_exit_code(1, 1);
		exit(1);
	}
}
