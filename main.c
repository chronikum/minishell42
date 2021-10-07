#include "./includes/ft_minishell.h"

void ft_quit()
{
	exit(0);
}

int	main(int argc, char **argv)
{
	if (argc < 1 && argv)
		return (-1);
	while (1)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, ft_quit);
		char *read_line;
		read_line = readline(">");
		if (ft_strncmp(read_line, "exit", ft_strlen(read_line)) == 0)
			exit(0);
		add_history(read_line);
	}
	return (0);
}
