#include "./includes/ft_minishell.h"

/*
**	Quits the program
*/
void	ft_quit()
{
	ft_freeall();
	exit(0);
}

/*
**	Signal handler SIGINT
**	Handles incoming SIGINT signal by making a new line
**	and replacing current input on the new line with empty string.
**	Also, redisplays when done :)
*/
void	sig_handler_int(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

/**
 * Gets the command list for the give char array
 */
void	ft_get_command_list(char *command)
{
	t_command	*list;
	t_pipes		*p;

	p = malloc(sizeof(t_pipes));
	list = ft_parse_in_commands(command);
	t_envlist *envp = ft_env_list(NULL);
	//Do this before entering PIPEX
	p->temp_fd = dup(STDIN_FILENO);
	p->stout = dup(1);
	while (list != NULL)
	{
		if (DEBUG)
			printf("COMMAND BEING EXECUTED : %s\n", list->command);
		ft_pipex(p, list, envp);
		list = list->next;
	}
	//single builtin dont fork builtin with pipes then you need to fork
}

/*
	Runs if the command is a builtin one.
	Returns one for builtin commands
*/
int	ft_run_builtin(char *command)
{
	if (ft_strncmp(command, "pwd", ft_strlen("pwd")) == 0)
		return (ft_pwd());
	else if (ft_strncmp(command, "exit", ft_strlen("exit")) == 0)
		ft_quit();
	else if (ft_strncmp(command, "env", ft_strlen("env")) == 0)
		return (ft_env());
	else if (ft_strncmp(command, "echo ", ft_strlen("echo ")) == 0)
		return (ft_echo(command, 0));
	else
		ft_get_command_list(command);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char *cmd;
	int	oldstdin = dup(0);
	int	oldstdout = dup(1);

	ft_env_list(ft_create_env_list(envp));
	//ft_run_builtin("say -v Good Welcome to mini shell!");
	while (1 && argc && argv && envp)
	{
		dup2(oldstdin, 0);
		dup2(oldstdout, 1);
		signal(SIGQUIT, &ft_quit);
		signal(SIGINT, &sig_handler_int);
		// function read and check the input
		cmd = readline("mini\e[36mShell\033[0m \033[0;31m$\033[0m> ");
		if (cmd == NULL)
			ft_quit();
		if (ft_strncmp(cmd, "", ft_strlen(cmd)))
		{
			ft_run_builtin(cmd);
			add_history(cmd);
		}
		// split commands by | < > $
	}
	return (0);
}

//int	main(int argc, char **argv, char **envp)
//{
//	t_command	*command;
//	t_command	*command2;
//	t_command	*tmp;
//	t_pipes		*p;

//	command = malloc(sizeof(t_command));
//	command2 = malloc(sizeof(t_command));
//	tmp = malloc(sizeof(t_command));
//	p = malloc(sizeof(t_pipes));
//	ft_env_list(ft_create_env_list(envp));

//	//char *commmand_args2[3];
//	//commmand_args2[0] = "grep";
//	//commmand_args2[1] = "ft_";
//	//commmand_args2[2] = NULL;

//	//char *commmand_args[3];
//	//commmand_args[0] = "ls";
//	//commmand_args[1] = "-a";
//	//commmand_args[2] = NULL;

//	char *commmand_args2[2];
//	commmand_args2[0] = "cat";
//	commmand_args2[1] = NULL;

//	char *commmand_args[2];
//	commmand_args[0] = "<in";
//	commmand_args[1] = NULL;

//	(void)argv;
//	(void)argc;

//	//// second command
//	//command2 = malloc(sizeof(t_command));
//	//command2->args = commmand_args2;
//	//command2->command = "grep ft_";
//	//command2->in_flag = 7;
//	//command2->out_flag = STDOUT;
//	//command2->next = NULL;

//	//// first commands
//	//command = malloc(sizeof(t_command));
//	//command->args = commmand_args;
//	//command->command = "ls -a";
//	//command->in_flag = 7;
//	//command->out_flag = PIPE;
//	////command->next = NULL;
//	//command->next = command2;

//	// second command
//	command2 = malloc(sizeof(t_command));
//	command2->args = commmand_args2;
//	command2->command = "cat";
//	command2->in_flag = 7;
//	command2->out_flag = STDOUT;
//	command->builtin_sys_flag = BUILT_IN;
//	command2->next = NULL;

//	// first commands
//	command = malloc(sizeof(t_command));
//	command->args = commmand_args;
//	command->command = "<in";
//	command->file = "./in";
//	command->in_flag = IN;
//	command->out_flag = 7;
//	command->builtin_sys_flag = 7;
//	//command->next = NULL;
//	command->next = command2;



//	//Do this before entering PIPEX
//	p->temp_fd = dup(STDIN_FILENO);
//	p->stout = dup(1);

//	tmp = command;
//	while (tmp)
//	{
//		ft_pipex(p, tmp, ft_env_list(NULL));
//		//ft_pipex(p, tmp, ft_env_list(NULL)->envp);
//		tmp = tmp->next;
//	}
//	return (0);
//}
