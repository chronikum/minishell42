#include "../includes/ft_minishell.h"

/*
**	Catches all signals and decides what to do
*/
static void	ft_handle(int sig)
{
	if (sig == SIGINT)
		printf("\nHELLO");
}

int	ft_setup_signals()
{
	signal (SIGINT, ft_handle);
	pause();
	return (0);
}