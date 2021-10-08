#include "../includes/ft_minishell.h"

int	ft_pwd(void)
{
	char	*str;

	str = malloc(sizeof(char) * 50000);
	str = getcwd(str, 50000);
	if (!str)
		return (-1);
	printf("%s", str);
	free(str);
	return (0);
}

