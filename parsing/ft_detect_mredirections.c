#include "../includes/ft_minishell.h"

/*
Gets called when a quote is being seen. Toggles a int (pointer)
*/
static void	ft_toggle_quote(int *quote_toggle)
{
	if ((*quote_toggle))
		(*quote_toggle) = 0;
	else
		(*quote_toggle) = 1;
}

/*
	Increases counter by one and toggles quote counter if it encounters one
*/
static void	ft_increase_i_quote_handler(char *cmd, int *i, int *quote)
{
	if (cmd[(*i)] == '"')
		ft_toggle_quote(quote);
	(*i)++;
}

/*
	Checks for multiple redirections and returns count of them
*/
int ft_detect_mredirections(char *command)
{
	int	i;
	int	quote_closed;
	int	counted;

	i = 0;
	counted = 0;
	quote_closed = 1;
	while (command[i])
	{
		if (ft_single_inset(command[i], "<>") != -1 && quote_closed)
			counted++;
		ft_increase_i_quote_handler(command, &i, &quote_closed);
	}
	return (counted);
}
