#include "../includes/ft_minishell.h"

/*
	Gets the position of the not quote enclosed
	heredoc indicator
*/
static int		ft_get_heredoc_pos(char *string)
{
	int		quotes_closed;
	int		i;
	
	i = 0;
	quotes_closed = 1;
	
	while (string[i])
	{
		if (quotes_closed && string[i + 1])
		{
			if (string[i] == '<' && string[i + 1] == '<')
				return (i);
		}
		ft_increase_i_quote_handler(string, &i, &quotes_closed);
	}
	return (-1);
}

/*
	Adds the heredoc delimiter to the provided command
*/
void	ft_set_heredoc(t_command *command, char *string)
{
	int		delimiter_pos;
	char	*delimiter;
	char	*trimmed_string;
	
	delimiter_pos = ft_get_heredoc_pos(string);
	if (delimiter_pos == -1)
		return;
	trimmed_string = ft_gc_strtrim(&string[(delimiter_pos + 2)], " ");
	delimiter = ft_substr(trimmed_string, 0, ft_strlen_not_quoted(trimmed_string, " "));
	command->delimiter = delimiter;
}