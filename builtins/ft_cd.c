#include "../includes/ft_minishell.h"

int	ft_cd(char *path)
{
	ft_setenv("PWD", path);
	return(chdir(path));
}
