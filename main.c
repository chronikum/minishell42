#include "./includes/ft_minishell.h"

void	sig_handler_int(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		//rl_replace_line("", 1); // this needs a little love
		rl_redisplay();
	}
}

int	main(int argc, char **argv)
{
	while (1 && argc && argv)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &sig_handler_int);
		// function read and check the input
		char *input = readline("urgent! > ");
		if (input == NULL)
			ft_putstr_fd("exit\n", 1);
		if (ft_strncmp(input, "", ft_strlen(input)))
			add_history(input);
	}
	return (0);
}