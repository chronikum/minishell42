#include "../includes/ft_minishell.h"

void	ft_single_double_quote_handler(char *cmd, int *i, int *dq, int *sq)
{
	if (cmd[(*i)] == '\'')
		ft_toggle_quote(sq);
	if (cmd[(*i)] == '"')
		ft_toggle_quote(dq);
	(*i)++;
}

void	ft_usdq_handler(char *cmd, unsigned int *i, int *dq, int *sq)
{
	if (cmd[(*i)] == '\'')
		ft_toggle_quote(sq);
	if (cmd[(*i)] == '"')
		ft_toggle_quote(dq);
	(*i)++;
}
