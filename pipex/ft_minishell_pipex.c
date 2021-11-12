#include "../includes/ft_minishell.h"

void	ft_close(t_pipes *p)
{
	if (p->temp_fd)
		close(p->temp_fd);
	if (p->in)
		close(p->in);
	if (p->out)
		close(p->out);
	if (p->pipe[0])
		close(p->pipe[0]);
	if (p->pipe[1])
		close(p->pipe[1]);
	if (p->stout)
		close(p->stout);
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

int	ft_execute(t_command *commands, t_envlist *envp)
{
	t_child	*c;

	c = malloc(sizeof(t_child));
	if (commands->args[0][0] == '/')
		c->full_path = commands->original_string;
	else
		c->full_path = ft_find_executable_path(commands->args[0]);
	if (access(c->full_path, F_OK) != -1)
		execve(c->full_path, commands->args, envp->envp);
	if (access(c->full_path, F_OK) == -1 && c->i == 0)
		command_not_found(commands->original_string);
	exit(0);
}

void	ft_system_command(t_pipes *p, t_command *commands, t_envlist *envp)
{
	pid_t	pid;

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
		wait(0);
	}
}

void	ft_init_dup(t_pipes *p)
{
	dup2(p->temp_fd, 0);
}

void	ft_open_outfile(t_pipes *p, t_command *commands)
{
	if (commands->out_flag == OUT)
		p->out = open(&commands->files->file_name[2],
				 O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (commands->out_flag == APPEND)
		p->out = open(&commands->files->file_name[2],
				 O_RDWR | O_CREAT | O_APPEND, 0666);
	if (p->out == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(&commands->files->file_name[2], 2);
		ft_putendl_fd(": Permission denied", 2);
		commands->builtin_sys_flag = 7;
	}
}

void	ft_open_infile(t_pipes *p, t_command *commands)
{
	check_file(&commands->files->file_name[2]);
	p->temp_fd = open(&commands->files->file_name[2], O_RDONLY);
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
		exit(0);
	}
}

int	ft_run_builtin(t_command *command)
{
	if (ft_spongebob_strncmp(command->args[0],
			"pwd", ft_strlen("pwd")) == 0)
		return (ft_pwd());
	else if (ft_spongebob_strncmp(command->args[0],
			"exit", ft_strlen("exit")) == 0)
		ft_quit();
	else if (ft_spongebob_strncmp(command->args[0],
			"env", ft_strlen("env")) == 0)
		return (ft_env());
	else if (ft_spongebob_strncmp(command->args[0],
			"echo", ft_strlen("echo")) == 0)
		return (ft_echo(command));
	else if (ft_spongebob_strncmp(command->args[0],
			"export", ft_strlen("export")) == 0)
		return (builtin_export(command->original_string));
	else if (ft_spongebob_strncmp(command->args[0],
			"cd", ft_strlen("cd")) == 0)
		return (ft_cd(command));
	else if (ft_spongebob_strncmp(command->args[0],
			"unset", ft_strlen("unset")) == 0)
		return (ft_unset(command));
	return (0);
}

void	ft_here_doc(t_pipes *p, t_command *commands)
{
	char	*str;

	str = NULL;
	while (str == NULL || ft_spongebob_strncmp(str,
			commands->delimiter, ft_strlen(commands->delimiter)))
	{
		str = readline("> ");
		if (!ft_spongebob_strncmp(str,
				commands->delimiter, ft_strlen(commands->delimiter)))
			break ;
		ft_putendl_fd(str, p->pipe[1]);
	}
	ft_pipe_after_dup(p);
}

void	ft_multi_redirections(t_pipes *p, t_command *commands)
{
	t_files	*temp;

	temp = commands->files;
	while (temp != NULL)
	{
		if (ft_strcmp(commands->args[0], temp->file_name) != 0)
		{
			if (commands->out_flag == OUT)
				open(temp->file_name, O_CREAT, 0666);
			if (commands->out_flag == APPEND)
				open(temp->file_name, O_CREAT, 0666);
			if (temp->is_last)
			{
				if (commands->out_flag == OUT)
					p->out = open(temp->file_name,
						O_RDWR | O_CREAT | O_TRUNC, 0666);
				if (commands->out_flag == APPEND)
					p->out = open(temp->file_name,
						O_RDWR | O_CREAT | O_APPEND, 0666);
				ft_outfile_dup(p);
			}
		}
		temp = temp->next;
	}
}

char *ft_command_from_path(char *args_zero)
{
	char	**splitted_path;
	int		len;

	splitted_path = ft_split(args_zero, '/');
	len = ft_array_len(splitted_path);
	return (splitted_path[len - 1]);
}

void	ft_pipex(t_pipes *p, t_command *commands, t_envlist *envp)
{
	ft_pipe(p);
	if (commands->file && commands->files->is_multiple)
		ft_multi_redirections(p, commands);
	if (commands->in_flag == IN)
		ft_open_infile(p, commands);
	if (commands->in_flag == HERE_DOC)
		ft_here_doc(p, commands);
	if (commands->out_flag == OUT || commands->out_flag == APPEND)
	{
		ft_open_outfile(p, commands);
		ft_outfile_dup(p);
	}
	ft_init_dup(p);
	if (commands->out_flag == STDOUT)
		ft_stdout_dup(p);
	if (commands->out_flag == PIPE)
		ft_pipe_pre_dup(p);
	if (commands->args[0][0] == '/')
		commands->args[0] = ft_command_from_path(commands->args[0]);
	if (commands->builtin_sys_flag == BUILT_IN)
		ft_run_builtin(commands);
	if (commands->builtin_sys_flag == SYS)
		ft_system_command(p, commands, envp);
	if (commands->out_flag == PIPE)
		ft_pipe_after_dup(p);
	if (commands->out_flag != PIPE)
		ft_close(p);
}

//ls > out >> out2 > out3 >> out4
