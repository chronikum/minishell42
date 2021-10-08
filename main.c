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
		rl_replace_line("", 1); // this needs a little love
		rl_redisplay();
	}
}

int	main(int argc, char **argv)
{
	char *cmd;

	while (1 && argc && argv)
	{
		signal(SIGQUIT, &ft_quit);
		signal(SIGINT, &sig_handler_int);
		// function read and check the input
		cmd = readline("\033[0;31mmini\e[36mShell\033[0m $ > ");
		if (cmd == NULL)
			ft_quit();
		if (ft_strncmp(cmd, "", ft_strlen(cmd)))
			add_history(cmd);
	}
	return (0);
}