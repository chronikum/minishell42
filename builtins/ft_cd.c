#include "../includes/ft_minishell.h"

int	ft_cd(t_command *command)
{
	ft_setenv("PWD", command->args[1]);
	if (chdir(command->args[1]) == -1)
		printf("bash: cd: %s: Not a directory\n", command->args[1]);
	return(0);
}
