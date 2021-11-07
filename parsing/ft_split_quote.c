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


/*
	Skips operators liek | < > << >> because
	those should not show up in the argument list
*/
static void	ft_skip_operators(unsigned int *i, char *cmd)
{
	while (ft_single_inset(cmd[(*i)], "|><") != -1)
		(*i)++;
}

/*
	Counts words. Can handle quotes with ease.
*/
int ft_new_word_counter(char *cmd)
{
	unsigned int	i;
	int quote_closed;
	int	words;
	char	*temp;

	quote_closed = 1;
	i = 0;
	words = 1;
	temp = ft_strtrim(cmd, "|<> ");
	while (temp[i])
	{
		if (temp[i] == ' ' && quote_closed)
		{
			words++;
			while (temp[i] == ' ' && temp[i])
				ft_increase_i_quote_handler(temp, &i, &quote_closed);
		}
		ft_increase_i_quote_handler(temp, &i, &quote_closed);
	}
	return (words);
}

static void	ft_reset_static_vars(unsigned int *i, unsigned int *saved)
{
	(*saved) = 0;
	(*i) = 0;
}


char *ft_get_next_word(char *cmd, int r)
{
	int quote_closed;
	int	words;
	char	*temp;
	static unsigned int	i = 0; // current iterator
	static unsigned int	saved = 0;

	quote_closed = 1;
	words = 1;
	temp = ft_strtrim(cmd, "|<> ");
	ft_skip_operators(&i, temp);
	saved = i;
	if (r)
		ft_reset_static_vars(&i, &saved);
	while (temp[i])
	{
		while (!quote_closed)
			ft_increase_i_quote_handler(temp, &i, &quote_closed);
		if (temp[i] == ' ')
		{
			while ((temp[i] == ' ') && temp[i])
				ft_increase_i_quote_handler(temp, &i, &quote_closed);
			return (ft_strtrim(ft_gc_substr(temp, saved, ft_strlenc(&temp[saved], ' ')), " "));
		}
		ft_increase_i_quote_handler(temp, &i, &quote_closed);
	}
	return (ft_strtrim(ft_gc_substr(temp, saved, ft_strlenc(&temp[saved], ' ')), " "));
}

/*
	Returns the word when the function finds a seperator character, a end of char pointer or
	a closing quote. The static variables need to be set to 0 after every iteration.
*/
//static char	*ft_get_next_word(char *s, char c, int r)
//{
//	// runtime variables
//	static unsigned int	i = 0; // current iterator
//	static unsigned int	saved = 0;

//	if (r)
//		ft_reset_static_vars(&i, &saved);

//	ft_skip_operators(&i, s);
//	saved = i;
//	while ((s[i] == c && s[i] && saved == 0))
//	{
//		i++;
//		saved++;
//	}
//	while (s[i])
//	{
//		ft_skip_operators(&i, s);
//		while (saved != 0 && (s[i] == c || s[i] == '"'))
//		{
//			saved++;
//			i++;
//		}
//		ft_skip_operators(&i, s);
//		if (s[i] == '"' && s[i]) // join in when starting character is a quote
//		{
//			i++;
//			while (s[i] != '"' && s[i])
//				i++;
//			ft_skip_operators(&saved, s);
//			return (ft_substr(s, saved, (i - saved - 1)));
//		}
//		ft_skip_operators(&i, s);
//		if (s[i] != c && s[i])
//		{
//			while (s[i] != c && s[i])
//			{
//				i++;
//				ft_skip_operators(&saved, s);
//				if (s[i] == '"')
//					return (ft_substr(s, saved, (i - saved)));
//				if (!s[i])
//					return (ft_substr(s, saved, (i - saved)));
//			}
//			ft_skip_operators(&saved, s);
//			if (s[i] == c || !s[i])
//				return (ft_substr(s, saved, (i - saved)));
//		}
//		i++;
//	}
//	return (NULL);
//}

char	**ft_split_quote(char *s, char c)
{
	char	**result;
	char	*current;
	int		i;
	int		wc;

	(void)c;
	i = 0;
	current = NULL;
	wc = ft_new_word_counter(s);
	result = ft_malloc(sizeof(char *) * (wc + 1));
	while (current || i == 0)
	{
		if (!current)
			current = ft_get_next_word(s, 1);
		if (!current)
			return (NULL);
		if (ft_strlen(current) != 0)
		{
			result[i] = current;
			i++;
		}
		current = ft_get_next_word(s, 0);
	}
	result[i] = NULL;
	return (result);
}
