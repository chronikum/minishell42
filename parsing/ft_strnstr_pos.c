#include "../includes/ft_minishell.h"

/*
	Makes sure the needle is neither being enclosed by double or single quotes.
	Ultimate quote handling function returning the position of the
	needle within the string as int
*/
int	ft_strnstr_now_quotes_pos(
		const char *haystack, const char *needle, size_t len)
{
	t_strnstr	*st;

	st = ft_get_strnstr((char *) needle, (char *) haystack);
	if (needle[0] == '\0')
		return (-1);
	while (haystack[st->i] != '\0' && st->i < len)
	{
		while (haystack[st->i + st->j] == needle[st->j] && needle[st->j]
			!= '\0' && (st->i + st->j) < len && st->quote_closed)
		{
			ft_usdq_handler((char *) &haystack[st->i], &st->j,
				&st->quote_closed, &st->quote_closed);
			if (st->j == st->needle_len)
				return (st->i);
		}
		ft_usdq_handler((char *) haystack,
			&st->i, &st->quote_closed, &st->quote_closed);
		st->j = 0;
	}
	return (-1);
}

/*
	Returns the index of a strnstr pos
*/
int	ft_strnstr_pos(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;
	char	*phaystack;

	i = 0;
	j = 0;
	needle_len = ft_strlen(needle);
	phaystack = (char *)haystack;
	if (needle[0] == '\0')
		return (-1);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j]
			&& needle[j] != '\0' && (i + j) < len)
		{
			j++;
			if (j == needle_len)
				return (i);
		}
		i++;
		j = 0;
	}
	return (-1);
}
