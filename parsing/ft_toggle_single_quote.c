
#include "../includes/ft_minishell.h"
/*
	Increases counter by one and toggles quote counter if it encounters one
*/
void	ft_increase_i_singlequote_handler(char *cmd, int *i, int *quote)
{
	if (cmd[(*i)] == '\'')
		ft_toggle_quote(quote);
	(*i)++;
}

/*
	Increases counter by one and toggles quote counter if it encounters one
*/
void	ft_increase_ui_singlequote_handler(char *cmd, 
	unsigned int *i, int *quote)
{
	if (cmd[(*i)] == '\'')
		ft_toggle_quote(quote);
	(*i)++;
}