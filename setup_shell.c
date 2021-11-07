#include "./includes/ft_minishell.h"

/*
	Runs setup methods like building the env list
	or setting initial ENV variables
*/
void	ft_init_shell(char **envp)
{
	ft_env_list(ft_create_env_list(envp));
	set_shell_envvariable();
}