#include "./includes/ft_minishell.h"

int global;

/*
**	Quits the program
*/
void	ft_quit_signal(int signal)
{
	(void) signal;
	if (global == 2)
	{
		global = 1;
	}
}

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
		global = 1;
	}
}

/**
 * Gets the command list for the give char array
 */
void	ft_execute_terminal_command(char *command)
{
	t_command	*list;
	t_pipes		*p;
	t_envlist	*envp;

	p = malloc(sizeof(t_pipes));
	command = ft_insert_exit_code(command);
	command = ft_translate_envs(command);
	command = ft_gc_strtrim(command, "|");
	if (ft_strlen(ft_gc_strtrim(command, " \"")) == 0)
		return;
	list = ft_parse_in_commands(command);
	envp = ft_env_list(NULL);
	p->temp_fd = dup(STDIN_FILENO);
	p->stout = dup(1);
	while (list != NULL)
	{
		ft_pipex(p, list, envp);
		list = list->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	int		oldstdin;
	int		oldstdout;

	oldstdin = dup(0);
	oldstdout = dup(1);
	cmd = NULL;
	ft_init_shell(envp);
	while (1 && argc && argv && envp)
	{
		dup2(oldstdin, 0);
		dup2(oldstdout, 1);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &sig_handler_int);
		cmd = readline(ft_get_nice_prompt());
		if (cmd == NULL)
			ft_quit();
		if (ft_strncmp(cmd, "", ft_strlen(cmd)))
		{
			ft_execute_terminal_command(cmd);
			add_history(cmd);
		}
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



//	////REGULAR TEST
//	//char *commmand_args2[3];
//	//commmand_args2[0] = "grep";
//	//commmand_args2[1] = "ft_";
//	//commmand_args2[2] = NULL;

//	//char *commmand_args[3];
//	//commmand_args[0] = "ls";
//	//commmand_args[1] = "-a";
//	//commmand_args[2] = NULL;






//	////INFILE TEST
//	//char *commmand_args2[2];
//	//commmand_args2[0] = "cat";
//	//commmand_args2[1] = NULL;

//	//char *commmand_args[2];
//	//commmand_args[0] = "<in";
//	//commmand_args[1] = NULL;






//	//////OUTFILE TEST
//	//char *commmand_args[2];
//	//commmand_args[0] = "ls";
//	//commmand_args[1] = NULL;






//	////HERE_DOC
//	char *commmand_args[2];
//	commmand_args[0] = "cat";
//	commmand_args[1] = NULL;






//	////REGULAR TEST
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






//	////INFILE TEST
//	//// second command
//	//command2 = malloc(sizeof(t_command));
//	//command2->args = commmand_args2;
//	//command2->command = "cat";
//	//command2->in_flag = 7;
//	//command2->out_flag = STDOUT;
//	//command->builtin_sys_flag = BUILT_IN;
//	//command2->next = NULL;

//	//// first commands
//	//command = malloc(sizeof(t_command));
//	//command->args = commmand_args;
//	//command->command = "<in";
//	//command->file = "./in";
//	//command->in_flag = IN;
//	//command->out_flag = 7;
//	//command->builtin_sys_flag = 7;
//	////command->next = NULL;
//	//command->next = command2;






//	//////OUTFILE TEST
//	//// first commands
//	//command = malloc(sizeof(t_command));
//	//command->args = commmand_args;
//	//command->command = "ls >out";
//	//command->file = "./out";
//	//command->in_flag = 7; // -1
//	//command->out_flag = OUT;
//	//command->builtin_sys_flag = BUILT_IN; //6
//	//command->next = NULL;






//	////HERE_DOC
//	command = malloc(sizeof(t_command));
//	command->args = commmand_args;
//	command->command = "/bin/cat";
//	command->delimiter = "delimiter";
//	command->in_flag = HERE_DOC;
//	command->out_flag = STDOUT;
//	command->builtin_sys_flag = SYS;
//	command->next = NULL;




//	(void)argv;
//	(void)argc;

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
