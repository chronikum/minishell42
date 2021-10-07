#include "./includes/ft_minishell.h"

int	main(int argc, char **argv)
{
	if (argc < 1 && argv)
		return (-1);
	ft_setup_signals();
	signal (SIGQUIT, SIG_IGN);
	while (1)
	{
		signal(SIGINT, ft_handle_sig);
		char *read_line;
		read_line = readline(">");
	}
	return (0);
}
