/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_pipex_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:30:27 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 17:30:28 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

int	g_global;

void	ft_multi_redirections(t_pipes *p, t_command *commands)
{
	t_files	*temp;

	temp = commands->files;
	ft_mr_while_loop(p, commands, temp);
}

char	*ft_command_from_path(char *args_zero)
{
	char	**splitted_path;
	int		len;

	splitted_path = ft_split(args_zero, '/');
	len = ft_array_len(splitted_path);
	return (splitted_path[len - 1]);
}

void	ft_out_or_append(t_pipes *p, t_command *commands)
{
	ft_open_outfile(p, commands);
	ft_outfile_dup(p);
}

void	ft_io(t_pipes *p, t_command *commands)
{
	if (commands->files && commands->files->is_multiple)
		ft_multi_redirections(p, commands);
	if (commands->in_flag == IN)
		ft_open_infile(p, commands);
	if (commands->in_flag == HERE_DOC)
		ft_here_doc(p, commands);
	if ((commands->out_flag == OUT || commands->out_flag == APPEND)
		&& !(commands->files->is_multiple))
		ft_out_or_append(p, commands);
}

void	ft_pipex(t_pipes *p, t_command *commands, t_envlist *envp)
{
	ft_pipe(p);
	ft_io(p, commands);
	ft_init_dup(p);
	if (!commands->args)
		return ;
	if (commands->out_flag == STDOUT)
		ft_stdout_dup(p);
	if (commands->out_flag == PIPE)
		ft_pipe_pre_dup(p);
	if (commands->args)
	{
		if (commands->args[0][0] == '/'
			|| (commands->args[0][0] == '.' && commands->args[0][1] == '.'))
			commands->args[0] = ft_command_from_path(commands->args[0]);
	}
	if (commands->builtin_sys_flag == BUILT_IN)
		ft_set_most_recent_exit_code(ft_run_builtin(commands), 1);
	if (commands->builtin_sys_flag == SYS && commands->args[0][0] != '.')
		ft_system_command(p, commands, envp);
	if (commands->out_flag == PIPE)
		ft_pipe_after_dup(p);
	ft_close(p, commands);
}
