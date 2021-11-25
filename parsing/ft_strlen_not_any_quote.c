#include "../includes/ft_minishell.h"

/*
	Returns the length of the current position
	until we meet a character in the set.
	This is being used to as example find < in
	a not quoted part of a string and get the
	distance to it. Neither double or
	single quote!
*/
int	ft_strlen_not_quoted(char *str, char const *set)
{
	int	count;
	int	quote_closed;
	int	single_quote;

	count = 0;
	quote_closed = 1;
	single_quote = 1;
	while (str[count])
	{
		if (ft_single_inset(str[count], set) != -1 && quote_closed && single_quote)
			return (count);
		ft_single_double_quote_handler(str, &count, &quote_closed, &single_quote);
	}
	return (count);
}
