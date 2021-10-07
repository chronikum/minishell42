#include "./includes/ft_minishell.h"

void	ft_handle_sig(int sig)
{
	if (sig)
		sig = 1;
	rl_on_new_line(); // Regenerate the prompt on a newline
	rl_replace_line("", 0); // Clear the previous text
	rl_redisplay();
}