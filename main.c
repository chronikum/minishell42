#include "./includes/ft_minishell.h"

int	main(int argc, char **argv)
{
	char *read_line;

	if (argc < 1)
		return (-1);
	if (argv)
		read_line = readline("Hello: ");
	add_history (read_line);
	return (0);
}
