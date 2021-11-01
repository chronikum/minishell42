#include "../includes/ft_minishell.h"

//void	ft_close(t_pipes *p)
//{
//	close(p->temp_fd);
//	close(p->in);
//	close(p->out);
//    close(p->pipe[1]);
//}

void	ft_pipe_after_dup(t_pipes *p)
{
	close(p->pipe[1]);
	//close(p->temp_fd);
	dup2(p->pipe[0], p->temp_fd);
	//close(p->pipe[0]);
}

void	ft_pipe_pre_dup(t_pipes *p)
{
	close(p->pipe[0]);
	dup2(p->pipe[1], 1);
	//close(p->pipe[1]); remove this line?
}

//void	ft_outfile_dup(t_pipes *p)
//{
//	close(p->pipe[1]);
//	//dup2(p->temp_fd, 0);
//	//close(p->temp_fd);
//	dup2(p->out, 1);
//}

int ft_execute(t_command *commands, t_envlist *envp)
{
    t_child	c;
	//if (!envp)
	//	write(2, "fuck\n", 5);
	//while (envp != NULL)
	//{
	//	printf("flag = %s\n", envp->full_line);
	//	envp = envp->next;
	//}
	
    c.cmnd = commands->args;
	c.paths = envp->envp;
	c.paths = path_finder(envp->envp);
	c.i = ft_array_len(c.paths);
	while (c.i >= 0)
	{
		c.temp = ft_strjoin(c.paths[c.i], "/");
		c.full_path = ft_strjoin(c.temp, c.cmnd[0]);
		if (access(c.full_path, F_OK) != -1)
			execve(c.full_path, c.cmnd, envp->envp);
		if (access(c.full_path, F_OK) == -1 && c.i == 0)
			command_not_found(commands->command);
		ft_custom_free(&c.full_path, &c.temp, 'S');
		c.i--;
	}
	ft_custom_free(c.cmnd, c.paths, 'D');
	exit(0);
}

void    ft_system_command(t_command *commands, t_envlist *envp)
{
	pid_t	pid;
    pid = fork();
    if (pid == -1)
	    exit(0);
	if (pid == 0)
	    ft_execute(commands, envp);
	if (pid != 0)
		wait(0);
}

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

void    ft_open_infile(t_pipes *p, t_command *commands)
{
	check_file(commands->file, 'R');
    p->temp_fd = open(commands->file, O_RDONLY);
    if (p->temp_fd == -1)
        p->temp_fd = 5;
}

void    ft_init_dup(t_pipes *p)
{
    dup2(p->temp_fd, 0);
	//p->temp_fd = dup(STDIN_FILENO);
}

void    ft_pipe(t_pipes *p)
{
    if (pipe(p->pipe) == -1)
	{
        perror("Error");
	    exit(0);
	}
}

void	ft_pipex(t_pipes p, t_command *commands, t_envlist *envp)
{
    ft_pipe(&p);
    //if (commands->in_flag == IN)
    //    ft_open_infile(&p, commands);
    ft_init_dup(&p);
    //if (commands->flag == OUT || commands->flag == RIGHT)
    //    ft_open_outfile(&p, commands);
    if (commands->flag == PIPE)
        ft_pipe_pre_dup(&p); 
	//if (commands->flag == STDOUT)
    //    dup2(1, STDOUT);
    //if (commands->flag == OUT || commands->flag == RIGHT)
    //    ft_outfile_dup(&p);
    //if (commands->op == BUILT)
    //    ft_run_builtin(XXX);
    //if (commands->op == SYS)
    ft_system_command(commands, envp);
    if (commands->flag == PIPE)
        ft_pipe_after_dup(&p);
	//if (commands->flag != PIPE)
    //ft_close(&p);
}
