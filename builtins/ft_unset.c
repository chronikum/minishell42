#include "../includes/ft_minishell.h"

/*


*/
int	ft_unset(t_command *command)
{
	if (command->args[1])
		return (ft_del_envlist(command->args[1]));
	return (0);
}