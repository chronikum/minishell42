#include "../includes/ft_minishell.h"

static void ft_single_double_quote_handler(char *cmd, unsigned int *i, int *dq, int *sq)
{
	if (cmd[(*i)] == '\'')
		ft_toggle_quote(sq);
	if (cmd[(*i)] == '"')
		ft_toggle_quote(dq);
	(*i)++;
}

/*
	Counts words. Can handle quotes with ease.
*/
int	ft_new_word_counter(char *cmd)
{
	unsigned int	i;
	int				quote_closed;
	int				words;
	char			*temp;

	quote_closed = 1;
	i = 0;
	words = 1;
	temp = ft_gc_strtrim(cmd, "| ");
	while (temp[i])
	{
		if (temp[i] == ' ' && quote_closed)
		{
			words++;
			while (temp[i] == ' ' && temp[i])
				ft_increase_ui_quote_handler(temp, &i, &quote_closed);
		}
		ft_increase_ui_quote_handler(temp, &i, &quote_closed);
	}
	return (words);
}

static void	ft_reset_static_vars(unsigned int *i, unsigned int *saved)
{
	(*saved) = 0;
	(*i) = 0;
}

char	*ft_get_next_word(char *cmd, int r)
{
	static unsigned int	saved = 0;
	static unsigned int	i = 0; // current iterator
	int					quote_closed;
	int					quote_counter;
	char				*temp;

	quote_closed = 1;
	temp = ft_gc_strtrim(cmd, "| ");
	saved = i;
	if (r)
		ft_reset_static_vars(&i, &saved);
	while (temp[i])
	{
		quote_counter = 0;
		if (temp[i] == '"')
		{
			ft_increase_ui_quote_handler(temp, &i, &quote_closed);
			while (!quote_closed)
			{
				quote_counter++;
				ft_increase_ui_quote_handler(temp, &i, &quote_closed);
			}
			return (ft_gc_strtrim(ft_gc_substr(temp,
						saved, (quote_counter + 1)), " "));
		}
		if (temp[i] == ' ' && quote_closed)
		{
			while (temp[i] == ' ' && temp[i])
				ft_increase_ui_quote_handler(temp, &i, &quote_closed);
			return (ft_gc_strtrim(ft_gc_substr(temp,
						saved, ft_strlenc(&temp[saved], ' ')), " "));
		}
		ft_increase_ui_quote_handler(temp, &i, &quote_closed);
	}
	return (ft_gc_strtrim(ft_gc_substr(temp,
				saved, ft_strlenc(&temp[saved], ' ')), " "));
}

char	**ft_splint(char *s)
{
	char	**result;
	char	*current;
	int		i;
	int		wc;
	char	*to_use;

	i = 0;
	to_use = ft_gc_substr(s, 0, ft_strlen_not_quoted(s, "<>"));
	current = NULL;
	wc = ft_new_word_counter(to_use);
	result = ft_malloc(sizeof(char *) * (wc + 1));
	while (current || i == 0)
	{
		if (!current)
			current = ft_gc_strtrim(ft_get_next_word(to_use, 1), "\"");
		if (!current)
			return (NULL);
		if (ft_strlen(current) != 0)
		{
			result[i] = current;
			i++;
		}
		current = ft_gc_strtrim(ft_get_next_word(to_use, 0), "\"");
	}
	result[i] = NULL;
	return (result);
}