#include "../includes/ft_minishell.h"

int	ft_pwd(void)
{
	char	str[50000];

	str = getwcd(str, 50000);
	if (str == NULL)
		return (-1);
	printf("%s", str);
	return (0);
}

