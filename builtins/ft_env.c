#include "../includes/ft_minishell.h"

/*
** @TODO
*/
int	ft_env(void)
{
	char	*str;

	str = getenv("asd");
	if (!str)
		return (-1);
	printf("%s", str);
	free(str);
	return (0);
}

