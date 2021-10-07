#include "./includes/ft_minishell.h"

int	main(int argc, char **argv)
{
	if (argc < 1 && argv)
		return (-1);
	while (1)
	{
		signal(SIGINT, SIG_IGN);
		char *read_line;
		read_line = readline(">");
	}
	return (0);
}
