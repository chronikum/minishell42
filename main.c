#include "./includes/ft_minishell.h"

//char	*rl_gets(void)
//{
//	char *line_read;

//	line_read = malloc(5000);
//  	/* If the buffer has already been allocated,
//    return the memory to the free pool. */
//	if (line_read)
//	{
//      free (line_read);
//      line_read = (char *)NULL;
//	}

//	/* Get a line from the user. */
//  	line_read = readline ("");

//	/* If the line has any text in it,
//    save it on the history. */
//  	if (line_read && *line_read)
//	  add_history (line_read);
	  
//	  return (line_read);
//}

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

//readline
//history
//signals
