#include "../includes/ft_minishell.h"

/*
	We can get or set the most recent exit code here
*/
int	ft_set_most_recent_exit_code(int exit_code, int set)
{
	static int	exit_code_saved = 0;
	if (set == 1)
	{
		exit_code_saved = exit_code;
		return (1);
	}
	return (exit_code_saved);
}
