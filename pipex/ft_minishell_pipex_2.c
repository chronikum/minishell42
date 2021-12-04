#include "../includes/ft_minishell.h"

int	g_global;

int	ft_run_builtin(t_command *commands)
{
	if (ft_sb_strcmp(commands->args[0],
			"pwd") == 0)
		return (ft_pwd());
	else if (ft_sb_strcmp(commands->args[0],
			"exit") == 0)
		ft_quit();
	else if (ft_sb_strcmp(commands->args[0],
			"env") == 0)
		return (ft_env());
	else if (ft_sb_strcmp(commands->args[0],
			"echo") == 0)
		return (ft_echo(commands));
	else if (ft_sb_strcmp(commands->args[0],
			"export") == 0)
		return (builtin_export(commands->original_string));
	else if (ft_sb_strcmp(commands->args[0],
			"cd") == 0)
		return (ft_cd(commands));
	else if (ft_sb_strcmp(commands->args[0],
			"unset") == 0)
		return (ft_unset(commands));
	return (0);
}

void	sig_handler_int2(int signal)
{
	if (signal == SIGINT)
		g_global = 1;
	if (signal == SIGQUIT)
		g_global = 2;
}

void	ft_here_doc(t_pipes *p, t_command *commands)
{
	char	*str;

	str = NULL;
	g_global = 2;
	while (str == NULL || ft_strcmp_len(str,
			commands->delimiter))
	{
		str = readline("> ");
		if (str)
		{
			if (ft_strlen(str) == ft_strlen(commands->delimiter))
			{
				if (!ft_strcmp_len(str, commands->delimiter) || g_global == 1)
					break ;
			}
		}
		ft_putendl_fd(str, p->pipe[1]);
	}
	ft_pipe_after_dup(p);
}

int	ft_mr_open_last(t_pipes *p, t_command *commands, t_files *temp)
{
	if (commands->out_flag == OUT)
		p->out = open(temp->file_name,
				O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (commands->out_flag == APPEND)
	{
		p->out = open(temp->file_name,
				O_RDWR | O_CREAT | O_APPEND, 0777);
	}
	if (p->out == -1)
	{
		ft_open_error(p, commands);
		return (-1);
	}
	return (0);
}

void	ft_mr_while_loop(t_pipes *p, t_command *commands, t_files	*temp)
{
	while (temp != NULL && commands->args)
	{
		if (ft_strcmp(commands->args[0], temp->file_name) != 0)
		{
			if (temp->is_last)
			{
				if (ft_mr_open_last(p, commands, temp) == -1)
					break ;
				ft_outfile_dup(p);
			}
			else if (commands->out_flag == OUT || commands->out_flag == APPEND)
			{
				p->out = open(temp->file_name, O_CREAT | O_TRUNC, 0777);
				close(p->out);
				if (p->out == -1)
				{
					ft_open_error(p, commands);
					break ;
				}
			}
		}
		temp = temp->next;
	}
}
