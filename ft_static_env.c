#include "./includes/ft_minishell.h"

char **ft_enver(char **enver)
{
	static char **env = NULL;
	if (enver)
		env = enver;
	return (env);
}