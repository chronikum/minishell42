#include "../includes/ft_minishell.h"

/*
**	Catches all signals and decides what to do
*/
static void	ft_handle(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR2)
		ft_sig_convert(1);
	else if (sig == SIGUSR1)
		ft_sig_convert(0);
	if (context)
		sig = 1;
	kill(siginfo->si_pid, SIGUSR1);
}

int	ft_setup_signals()
{
	struct sigaction	sig_catcher;

	sigemptyset(&sig_catcher.sa_mask);
	sig_catcher.sa_flags = 0x0040;
	sig_catcher.sa_sigaction = ft_handle;
	sigaction (SIGUSR1, &sig_catcher, NULL);
}