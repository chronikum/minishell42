#include "../includes/ft_minishell.h"

t_strnstr	*ft_get_strnstr(char *needle, char *haystack)
{
	t_strnstr	*strnstrn;

	strnstrn = malloc(sizeof(t_strnstr));
	strnstrn->i = 0;
	strnstrn->j = 0;
	strnstrn->needle_len = ft_strlen(needle);
	strnstrn->phaystack = (char *)haystack;
	strnstrn->quote_closed = 1;
	return (strnstrn);
}

char	*ft_strnstr_quotes(const char *haystack, const char *needle, size_t len)
{
	t_strnstr	*st;

	st = ft_get_strnstr((char *) needle, (char *) haystack);
	if (needle[0] == '\0')
		return (st->phaystack);
	while (haystack[st->i] != '\0' && st->i < len)
	{
		while (haystack[st->i + st->j] == needle[st->j] && needle[st->j]
			!= '\0' && (st->i + st->j) < len && st->quote_closed)
		{
			ft_inc_uqh((char *) &haystack[st->i], &st->j, &st->quote_closed);
			if (st->j == st->needle_len)
				return (&st->phaystack[st->i]);
		}
		ft_inc_uqh((char *) haystack, &st->i, &st->quote_closed);
		st->j = 0;
	}
	return (NULL);
}

/*
	Searches a string not being surround by single quotes
*/
char	*ft_strnstr_single_quotes(
		const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	needle_len;
	char			*phaystack;
	int				quote_closed;

	i = 0;
	j = 0;
	quote_closed = 1;
	needle_len = ft_strlen(needle);
	phaystack = (char *)haystack;
	if (needle[0] == '\0')
		return (phaystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j]
			&& needle[j] != '\0' && (i + j) < len && quote_closed)
		{
			ft_incs_uihand((char *) &haystack[i], &j, &quote_closed);
			if (j == needle_len)
				return (&phaystack[i]);
		}
		ft_incs_uihand((char *) haystack, &i, &quote_closed);
		j = 0;
	}
	return (NULL);
}

/*
	Makes sure the needle is neither being enclosed by double or single quotes.
	Ultimate quote handling function
*/
char	*ft_strnstr_nowhere_quotes(
		const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	needle_len;
	char			*phaystack;
	int				quote_closed;

	i = 0;
	j = 0;
	quote_closed = 1;
	needle_len = ft_strlen(needle);
	phaystack = (char *)haystack;
	if (needle[0] == '\0')
		return (phaystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j]
			&& needle[j] != '\0' && (i + j) < len && quote_closed)
		{
			ft_usdq_handler((char *) &haystack[i], &j, &quote_closed, &quote_closed);
			if (j == needle_len)
				return (&phaystack[i]);
		}
		ft_usdq_handler((char *) haystack, &i, &quote_closed, &quote_closed);
		j = 0;
	}
	return (NULL);
}
