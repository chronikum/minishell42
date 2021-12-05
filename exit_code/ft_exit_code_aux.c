#include "../includes/ft_minishell.h"

void	ft_strinc_exitcode_aux(char *command, t_exit_code_aux *h)
{
	ft_strncat(h->result, &command[h->i], 1);
	h->total++;
	ft_incs_uihand(command, &h->i, &h->quote_closed);	
}