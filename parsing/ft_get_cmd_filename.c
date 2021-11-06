#include "../includes/ft_minishell.h"

/*
	Gets the filename after a < or > or >> operation.
	Skips whitespaces at the beginning if there are and
	then goes until it finds the end of the string
	or a new whitespace or seperator sign.

	TODO FIX: Check if it would currently skip >> too
*/
char *ft_get_cmd_filename(char *cmd, int *i)
{
	char *filename;

	while (ft_strlen_set(&cmd[(*i)], "|<>") == -1)
		(*i)++;
	filename = ft_strtrim(ft_substr(cmd, (*i), ft_strlen_set(&cmd[(*i)], "|<> ")), " ");

	return (filename);
}