#include "../includes/ft_minishell.h"

/*
	Makes sure the needle is neither being enclosed by double or single quotes.
	Ultimate quote handling function returning the position of the
	needle within the string as int
*/
int	ft_strnstr_now_quotes_pos(
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
		return (-1);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j]
			&& needle[j] != '\0' && (i + j) < len && quote_closed)
		{
			ft_u_single_double_quote_handler(
				(char *) &haystack[i], &j, &quote_closed, &quote_closed);
			if (j == needle_len)
				return (i);
		}
		ft_u_single_double_quote_handler(
			(char *) haystack, &i, &quote_closed, &quote_closed);
		j = 0;
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
