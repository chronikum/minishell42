#include "../includes/ft_minishell.h"

/*
	Sets the shell name in the SHELL env variable
	(likes bash does!)
*/
void	set_shell_envvariable(void)
{
	ft_setenv("SHELL", "minishell");
}
