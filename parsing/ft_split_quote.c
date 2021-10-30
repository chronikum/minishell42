#include "../includes/ft_minishell.h"

static void	ft_reset_static_vars(unsigned int *i, unsigned int *saved)
{
	(*saved) = 0;
	(*i) = 0;
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
	Returns the word when the function finds a seperator character, a end of char pointer or
	a closing quote. The static variables need to be set to 0 after every iteration.
*/
static char	*ft_get_next_word(char *s, char c, int r)
{
	// runtime variables
	static unsigned int	i = 0; // current iterator
	static unsigned int	saved = 0;

	if (r)
		ft_reset_static_vars(&i, &saved);

	ft_skip_operators(&i, s);
	saved = i;
	while ((s[i] == c && s[i] && saved == 0))
	{
		i++;
		saved++;
	}
	while (s[i])
	{
		ft_skip_operators(&i, s);
		while (saved != 0 && (s[i] == c || s[i] == '"'))
		{
			saved++;
			i++;
		}
		ft_skip_operators(&i, s);
		if (s[i] == '"' && s[i]) // join in when starting character is a quote
		{
			i++;
			while (s[i] != '"' && s[i])
				i++;
			ft_skip_operators(&saved, s);
			return (ft_substr(s, saved, (i - saved - 1)));
		}
		ft_skip_operators(&i, s);
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
			{
				i++;
				ft_skip_operators(&saved, s);
				if (s[i] == '"')
					return (ft_substr(s, saved, (i - saved)));
				if (!s[i])
					return (ft_substr(s, saved, (i - saved)));
			}
			ft_skip_operators(&saved, s);
			if (s[i] == c || !s[i])
				return (ft_substr(s, saved, (i - saved)));
		}
		i++;
	}
	return (NULL);
}

static int	word_counter(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	words = 0;
	while (s[i])
	{
		if (s[i] == '"' && s[i])
		{
			i++;
			while (s[i] != '"' && s[i])
				i++;
			words++;
		}
		if (s[i] == '"')
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
			{
				i++;
				if (!s[i])
					return (++words);
			}
			words++;
		}
		i++;
	}
	return (words);
}


char	**ft_split_quote(char *s, char c)
{
	char	**result;
	char	*current;
	int		i;
	int		wc;

	i = 0;
	current = NULL;
	wc = word_counter(s, c);
	result = malloc(sizeof(char *) * (wc + 1));
	printf("GOIGN %d\n", wc);
	while (current || i == 0)
	{
		if (!current)
			current = ft_get_next_word(s, c, 1);
		result[i] = current;
		printf("CURRENT: %s\n", current);
		current = ft_get_next_word(s, c, 0);
		i++;
		//if (!current)
		//	exit(0);
	}
	//ft_arg_printer(result);
	result[i] = NULL;
	return (result);
}
