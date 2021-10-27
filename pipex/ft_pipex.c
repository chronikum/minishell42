#include "../includes/ft_minishell.h"

void	ft_open_out(t_pipes *p, /*PATH TO OUTFILE*/)
{
	p->out = open(/*PATH TO OUTFILE*/,
			O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (p->out == -1)
	{
		ft_putstr_fd("Permission denied: ", 2);
		ft_putendl_fd(/*NAME OF OUTFILE*/, 2);
		exit (0);
	}
}

int	child(t_pipes *p, char **argv, char **envp)
{
	t_child	var;

	dup2(p->temp_fd, 0);
	close(p->pipe[0]);
	//if last command && outfile exists --> write into outfile
	//{
	//	ft_open_out(p, argv);
	//	ft_double_dub(t_pipes *p);
	//}
	//if last command && outfile not exists --> write to stdout
	// dup2(stout, 1);
	//else:
	dup2(p->pipe[1], 1);
	var.cmnd = ft_split(/*full cmd name in list structname->fullpath */, ' ');
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
		ft_custom_free(&var.full_path, &var.temp, 'S'); //include this!
		var.i--;
	}
	ft_custom_free(var.cmnd, var.paths, 'D');
	exit(0);
}

void	cutlery_close(t_pipes *p)
{
	close(p->temp_fd);
	close(p->in);
	close(p->out);
	close(p->stin);
	close(p->stout);
}

void	cutlery_dup(t_pipes *p)
{
	close(p->pipe[1]);
	close(p->temp_fd);
	dup2(p->pipe[0], p->temp_fd);
	close(p->pipe[0]);
}

void	cutlery(t_pipes *p, char **argv, char **envp)
{
	pid_t	pid;
	int		processes;

	processes = p->argc_process;
	while (processes > 0)
	{
		if (pipe(p->pipe) == -1)
		{
			perror("Error");
			exit(0);
		}
		//p->cmnd_count++; //probably delete this
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
		wait(0);
		//parent(p, prnt, argv, envp); //probably delete this
	cutlery_close(p);
}

int	execution(int argc, char **argv, char **envp)
{
	t_pipes		p;

	p .argc_process = argc; //argc will be length of lists
	p.stin = dup(0);
	p.stout = dup(1);
	p.cmnd_count = 1;
	//check it with <
	check_file(argv[1], 'R');
	p.in = open(argv[1], O_RDONLY);
	if (p.in == -1)
	{
		p.temp_fd = 5;
		p.cmnd_count++;
		p.argc_process--;
	}
	cutlery(&p, argv, envp);
	return (0);
}
