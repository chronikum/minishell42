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
static void	ft_increase_i_quote_handler(char *cmd, unsigned int *i, int *quote)
{
	if (cmd[(*i)] == '"')
		ft_toggle_quote(quote);
	(*i)++;
}

static void	ft_reset_static_vars(unsigned int *i, unsigned int *saved)
{
	(*saved) = 0;
	(*i) = 0;
}

static char	*ft_get_next_word(char *cmd, int r, char *set)
{
	static unsigned int	saved = 0;
	static unsigned int	i = 0; // current iterator
	int					quote_closed;
	int					quote_counter;
	char				*temp;

	quote_closed = 1;
	temp = ft_gc_strtrim(cmd, " ");
	saved = i;
	if (r)
		ft_reset_static_vars(&i, &saved);
	while (temp[i])
	{
		quote_counter = 0;
		if (temp[i] == '"')
		{
			ft_increase_i_quote_handler(temp, &i, &quote_closed);
			while (!quote_closed)
			{
				quote_counter++;
				ft_increase_i_quote_handler(temp, &i, &quote_closed);
			}
			return (ft_gc_strtrim(ft_gc_substr(temp,
						saved, (quote_counter + 1)), " "));
		}
		if ((ft_single_inset(temp[i], set) != -1) && quote_closed)
		{
			while ((ft_single_inset(temp[i], set) != -1) && temp[i])
				ft_increase_i_quote_handler(temp, &i, &quote_closed);
			return (ft_gc_strtrim(ft_gc_substr(temp,
						saved, ft_strlen_set(&temp[saved], set)), " "));
		}
		ft_increase_i_quote_handler(temp, &i, &quote_closed);
	}
	return (ft_gc_strtrim(ft_gc_substr(temp,
				saved, ft_strlen_set(&temp[saved], set)), " "));
}

char	**ft_multi_splint(char *s, char *splitter)
{
	char	**result;
	char	*current;
	int		i;
	int		wc;

	i = 0;
	current = NULL;
	wc = ft_detect_mredirections(s);
	result = ft_malloc(sizeof(char *) * (wc + 1));
	while (current || i == 0)
	{
		if (!current)
			current = ft_gc_strtrim(ft_get_next_word(s, 1, splitter), "\"");
		if (!current)
			return (NULL);
		if (ft_strlen(current) != 0)
		{
			result[i] = current;
			i++;
		}
		current = ft_gc_strtrim(ft_get_next_word(s, 0, splitter), "\"");
	}
	result[i] = NULL;
	return (result);
}
