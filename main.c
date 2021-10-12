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

void	ft_check_command(char *command)
{
	if (ft_strncmp(command, "pwd", ft_strlen(command)) == 0)
	{
		ft_pwd();
		printf("\n");
	}
	if (ft_strncmp(command, "exit", ft_strlen(command)) == 0)
		exit(0);
	if (ft_strncmp(command, "env", ft_strlen(command)) == 0)
		ft_env();
	if (ft_strncmp(command, "echo ", ft_strlen("echo ")) == 0)
		ft_echo(command, 0);
}

int	main(int argc, char **argv)
{
	char *cmd;

	while (1 && argc && argv)
	{
		signal(SIGQUIT, &ft_quit);
		signal(SIGINT, &sig_handler_int);
		// function read and check the input
		cmd = readline("mini\e[36mShell\033[0m \033[0;31m$\033[0m> ");
		if (cmd == NULL)
			ft_quit();
		if (ft_strncmp(cmd, "", ft_strlen(cmd)))
		{
			ft_check_command(cmd);
			add_history(cmd);
		}
	}
	return (0);
}