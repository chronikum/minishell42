#include "../includes/ft_minishell.h"
#include "ft_gc_functions.h"

/*
	Compares a string on characters ignoring if lower
	or uppercase. Only compares up to n characters.
	Will cast both strings to lowercase internally.
	Returns 0 if the strings are equal.
	It also checks if the strings have the same length.
*/
int	ft_spongebob_strncmp(char *s1, char *s2, int n)
{
	if (ft_strlen(s1) == ft_strlen(s2))
		return (ft_strncmp(ft_strtolowercase(s1), ft_strtolowercase(s2), n));
	return (-1);
}

int	ft_sb_strcmp(char *s1, char *s2)
{
	return (ft_strcmp(ft_strtolowercase(s1), ft_strtolowercase(s2)));
}
