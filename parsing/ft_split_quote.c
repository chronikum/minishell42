#include "../includes/ft_minishell.h"

static int	word_len_counter(char *s, char c)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
		i++;
	word_len = (i - j);
	return (word_len);
}
/*
	Returns the next word (if the word has quotes around they will be removed)
*/
static	char *ft_char_get_next(char *s, char c)
{
	static	int i = 0;
	int inner;
	char *next;

	inner = 0;
	next = malloc(sizeof(char) * word_len_counter(&s[i], c));
	while (s[i] != c)
	{
		if (s[i] != '"')
		{
			next[inner] = s[i];
			write(1, &next[inner], 1);
			inner++;
		}
		i++;
	}
	return (next);
}

/**
 * Counts how many unescaped quotes are in a character sequence
 */
static int	ft_count_quotes(char *characters)
{
	int counter;
	int counted_characters;

	counter = 0;
	counted_characters = 0;
	while (characters[counter])
	{
		if (characters[counter] == '"' && characters[counter - 1] != '\\')
			counted_characters++;
		counter++;
	}
	return (counted_characters);
}
// fix leaks here
static t_list	*ft_str_to_list(char *s, char c)
{
	char *current;
	t_list *start;

	current = ft_char_get_next(s, c);
	while (current)
	{
		current = ft_char_get_next(s, c);
		if (current)
			ft_lstadd_back(&start, ft_lstnew(current));
	}
	return (start);
}

static char	**ft_list_to_pp(t_list *start)
{
	char **result;
	int i;

	i = 0;
	result = malloc(sizeof(char *) * (ft_lstsize(start) + 1));
	while (start)
	{
		result[i] = ft_strdup((char *) start->content);
		start = start->next;
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split_quote(char *s, char c)
{
	char	**result;
	t_list	*start;

	if ((ft_count_quotes(s) % 2 != 0))
		return (NULL);
	if (ft_count_quotes(s) > 0)
	{
		start = ft_str_to_list(s, c);
			if (!start)
				return (NULL);
	}
	else
		return (ft_split(s, c));
	result = ft_list_to_pp(start);
	return (result);
}
