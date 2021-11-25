#include "../includes/ft_minishell.h"

char	*ft_strnstr_quotes(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	needle_len;
	char	*phaystack;
	int		quote_closed;

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
			ft_increase_ui_quote_handler((char *) &haystack[i], &j, &quote_closed);
			if (j == needle_len)
				return (&phaystack[i]);
		}
		ft_increase_ui_quote_handler((char *) haystack, &i, &quote_closed);
		j = 0;
	}
	return (NULL);
}

/*
	Searches a string not being surround by single quotes
*/
char	*ft_strnstr_single_quotes(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	needle_len;
	char	*phaystack;
	int		quote_closed;

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
			ft_increase_i_singlequote_handler((char *) &haystack[i], &j, &quote_closed);
			if (j == needle_len)
				return (&phaystack[i]);
		}
		ft_increase_i_singlequote_handler((char *) haystack, &i, &quote_closed);
		j = 0;
	}
	return (NULL);
}
