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

static char	*ft_get_delimiter(t_command* commmand, char *string, int d_pos)
{
	char	*delimiter;
	char	*trimmed_string;
	char	**heredoc_suffix;
	
	if (d_pos != 0)
	{
		trimmed_string = ft_gc_strtrim(&string[(d_pos + 2)], " ");
		delimiter = ft_substr(trimmed_string, 0, ft_strlen_not_any_quoted(trimmed_string, " "));
		return (delimiter);
	}
	heredoc_suffix = ft_gc_split(ft_gc_strtrim(&string[2], " "), ' ');
	if (heredoc_suffix[0])
	{
		if (heredoc_suffix[1])
		{
			commmand->args = malloc(sizeof(char *) * 2);
			commmand->args[0] = heredoc_suffix[1];
			commmand->args[1] = NULL;
		}
		return (heredoc_suffix[0]);
	}
	return (NULL);
}

/*
	Adds the heredoc delimiter to the provided command
*/
void	ft_set_heredoc(t_command *command, char *string)
{
	int		d_pos;
	
	d_pos = ft_get_heredoc_pos(string);
	printf("CURRENT HEREDOC POS: %d\n", d_pos);
	if (d_pos == -1)
		return;
	command->delimiter = ft_get_delimiter(command, string, d_pos);
}