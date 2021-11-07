#include "../includes/ft_minishell.h"

void	ft_close(t_pipes *p)
{
	close(p->temp_fd);
	close(p->in);
	close(p->out);
	close(p->pipe[0]);
	close(p->pipe[1]);
	close(p->stout);
}

void	ft_pipe_after_dup(t_pipes *p)
{
	close(p->pipe[1]);
	close(p->temp_fd);
	dup2(p->pipe[0], p->temp_fd);
	close(p->pipe[0]);
}

void	ft_pipe_pre_dup(t_pipes *p)
{
	dup2(p->pipe[1], 1);
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

//int ft_execute(t_command *commands, t_envlist *envp)
//{
//    t_child	*c;

//	c = malloc(sizeof(t_child));
//	c->paths = ft_split(getenv("PATH"), ':');
//	c->cmnd = commands->args;
//	c->i = ft_array_len(c->paths);
//	while (c->i >= 0)
//	{
//		c->temp = ft_strjoin(c->paths[c->i], "/");
//		c->full_path = ft_strjoin(c->temp, c->cmnd[0]);
//		if (access(c->full_path, F_OK) != -1)
//			execve(c->full_path, commands->args, envp->envp);
//		if (access(c->full_path, F_OK) == -1 && c->i == 0)
//			command_not_found(commands->command);
//		ft_custom_free(&c->full_path, &c->temp, 'S');
//		c->i--;
//	}
//	exit(0);
//}

int	ft_execute(t_command *commands, t_envlist *envp)
{
	t_child	*c;

	c = malloc(sizeof(t_child));
	c->full_path = ft_find_executable_path(commands->args[0]);
	if (access(c->full_path, F_OK) != -1)
		execve(c->full_path, commands->args, envp->envp);
	if (access(c->full_path, F_OK) == -1 && c->i == 0)
		command_not_found(commands->command);
	exit(0);
}

void	ft_system_command(t_pipes *p, t_command *commands, t_envlist *envp)
{
	pid_t	pid;

	(void) p;
	(void) envp;
	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid == 0)
	{
		close(p->pipe[0]);
		ft_execute(commands, envp);
	}
	if (pid != 0)
	{
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
		p->out = open(commands->file,
				 O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (commands->out_flag == APPEND)
		p->out = open(commands->file,
				 O_RDWR | O_CREAT | O_APPEND, 0666);
	if (p->out == -1)
	{
		ft_putstr_fd("Permission denied: ", 2);
		ft_putendl_fd(commands->file, 2);
		exit(0); //is exit right here?
	}
}

void	ft_open_infile(t_pipes *p, t_command *commands)
{
	check_file(commands->file, 'R');
	p->temp_fd = open(commands->file, O_RDONLY);
	if (p->temp_fd == -1)
		p->temp_fd = 5;
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
	if (ft_strncmp(command->args[0], "pwd", ft_strlen("pwd")) == 0)
		return (ft_pwd());
	else if (ft_strncmp(command->args[0], "exit", ft_strlen("exit")) == 0)
		ft_quit();
	else if (ft_strncmp(command->args[0], "env", ft_strlen("env")) == 0)
		return (ft_env());
	else if (ft_strncmp(command->args[0], "echo ", ft_strlen("echo ")) == 0)
		return (ft_echo(command->original_string, 0));
	else if (ft_strncmp(command->args[0], "export", ft_strlen("export")) == 0)
		return (builtin_export(command->original_string));
	return (0);
}

void	ft_pipex(t_pipes *p, t_command *commands, t_envlist *envp)
{
	ft_pipe(p);
	if (commands->in_flag == IN)
		ft_open_infile(p, commands);
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
	if (commands->builtin_sys_flag == BUILT_IN)
		ft_run_builtin(commands);
	if (commands->builtin_sys_flag == SYS) //!= 7 for test purposes == SYS
		ft_system_command(p, commands, envp);
	if (commands->out_flag == PIPE)
		ft_pipe_after_dup(p);
	//if (commands->out_flag == STDOUT || commands->out_flag == OUT
	//	|| commands->out_flag == APPEND)
	//	ft_close(p);
}
