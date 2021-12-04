#include "../includes/ft_minishell.h"

/*
	Helper function for translate env, appending a new
	char and increasing both total char count and
	iterator through the existing string
*/
void	ft_strncincrtotaluihand(char *command, t_envit *h)
{
	ft_strncat(h->result, &command[h->i], 1);
	h->total++;
	ft_incs_uihand(command, &h->i, &h->qclosed);	
}