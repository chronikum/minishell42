#include "./includes/ft_minishell.h"

void	ft_unnecessary_motd(void)
{
	printf("			 __ \n");
	printf(" __ _________ ____ ___  / /_\n");
	printf("/ // / __/ _ `/ -_) _ \\/ __/\n");
	printf("\\_,_/_/  \\_, /\\__/_//_/\\__/\n");
	printf("	/___/\n");
}

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
	ft_unnecessary_motd();
}
