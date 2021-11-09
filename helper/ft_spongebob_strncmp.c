#include "../includes/ft_minishell.h"
#include "ft_gc_functions.h"

/*
	Compares a string on characters ignoring if lower
	or uppercase. Only compares up to n characters.
	Will cast both strings to lowercase internally.
	Returns 0 if the strings are equal.

	Example: "HeLp Me" and "HELP ME" with size 7 are equal.

	Known bugs: Will cast everything to lowercase internally.
	This can cause problems under very specific conditions,
	but not in minishell ;)
*/
int	ft_spongebob_strncmp(char *s1, char *s2, int n)
{
	return (ft_strncmp(ft_strtolowercase(s1), ft_strtolowercase(s2), n));
}
