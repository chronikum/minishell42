#include "./includes/ft_minishell.h"

/*
	Makes the Control-C symbol after control c disappear
	by running stty -echoctl manually when
	minishell starts
*/
static void	ft_disable_control_c_symbol(void)
{
	ft_execute_terminal_command("stty -echoctl");
}
/*
	Runs setup methods like building the env list
	or setting initial ENV variables
*/
void	ft_init_shell(char **envp)
{
	ft_env_list(ft_create_env_list(envp));
	set_shell_envvariable();
	ft_disable_control_c_symbol();
}