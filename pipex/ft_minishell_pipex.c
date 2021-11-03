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

void	ft_stdout_dup(t_pipes *p)
{
	dup2(p->stout, 1);
}

int ft_execute(t_command *commands, t_envlist *envp) // the mistake is in t_command probably!
{
	t_child	*c;

	c = malloc(sizeof(t_child));
	c->cmnd = commands->args; // it seems that this does not have the content required
	c->full_path = ft_find_executable_path(commands->args[0]); // when going in here it fails
	if (access(c->full_path, F_OK) != -1)
		execve(c->full_path, commands->args, envp->envp);
	if (access(c->full_path, F_OK) == -1 && c->i == 0)
		command_not_found(commands->command);
	exit(0);
}

void    ft_system_command(t_pipes *p, t_command *commands, t_envlist *envp)
{
	pid_t	pid;

	(void) p;
	(void) envp;
	pid = fork(); // maybe something goes wrong with the fork?
	// ft_execute(commands, envp);
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

void    ft_init_dup(t_pipes *p)
{
	dup2(p->temp_fd, 0);
}

void    ft_pipe(t_pipes *p)
{
	if (pipe(p->pipe) == -1)
	{
		perror("Error");
		exit(0);
	}
}

void	ft_pipex(t_pipes *p, t_command *commands, t_envlist *envp)
{
	ft_pipe(p);
	ft_init_dup(p);
	if (commands->out_flag == STDOUT)
		ft_stdout_dup(p);
	if (commands->out_flag == PIPE)
		ft_pipe_pre_dup(p);
	ft_system_command(p, commands, envp);
	if (commands->out_flag == PIPE)
		ft_pipe_after_dup(p);
	if (commands->out_flag == STDOUT)
		ft_close(p);
}



//if (commands->flag == OUT || commands->flag == RIGHT)
//    ft_outfile_dup(&p);


//void	ft_outfile_dup(t_pipes *p)
//{
//	dup2(p->out, 1);
//}





//void	ft_open_outfile(t_pipes *p, t_command *commands)
//{
//    if (commands->flag == OUT)
//	    p->out = open(commands->file,
//			    O_RDWR | O_CREAT | O_TRUNC, 0666);
//    if (commands->flag == RIGHT)
//        p->out = open(commands->file,
//			    O_RDWR | O_CREAT | O_APPEND, 0666);
//	if (p->out == -1)
//	{
//		ft_putstr_fd("Permission denied: ", 2);
//		//ft_putendl_fd(/*NAME OF OUTFILE*/, 2);
//		exit(0);
//	}
//}






//if (commands->in_flag == IN)
//    ft_open_infile(&p, commands);


//void    ft_open_infile(t_pipes *p, t_command *commands)
//{
//	check_file(commands->file, 'R');
//    p->temp_fd = open(commands->file, O_RDONLY);
//    if (p->temp_fd == -1)
//        p->temp_fd = 5;
//}


//if (commands->op == BUILT)
//    ft_run_builtin(XXX);