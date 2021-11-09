#include "../includes/ft_minishell.h"

int	ft_cd(t_command *command)
{
	ft_setenv("PWD", command->args[1]);
	//access
	if (chdir(command->args[1]) == -1)
	{
		if (access(command->args[1], F_OK) == -1)
			printf("bash: cd: %s: No such file or directory\n", command->args[1]);
		else
			printf("bash: cd: %s: Not a directory\n", command->args[1]);
	}
	return(0);
}
