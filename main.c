#include "./includes/ft_minishell.h"

/*
**	Quits the program
*/
void	ft_quit()
{
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

void	ft_get_command_list(char *command)
{
	t_command *list;
	
	list = ft_parse_in_commands(command);
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
		exit(0);
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

	ft_env_list(ft_create_env_list(envp));
	while (1 && argc && argv && envp)
	{
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