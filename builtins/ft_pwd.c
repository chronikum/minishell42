#include "../includes/ft_minishell.h"

int	ft_pwd(void)
{
	char	*str;

	str = malloc(sizeof(char) * 4096);
	str = getcwd(str, 4096);
	if (!str)
		return (-1);
	printf("%s", str);
	free(str);
	return (0);
}

