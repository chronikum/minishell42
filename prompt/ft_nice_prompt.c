#include "../includes/ft_minishell.h"

/*
	Returns a nice styled prompt with the username and host
	machine
*/
char *ft_get_nice_prompt(void)
{
	char	*user;
	char	*command_prompt;
	char	*colored_part;
	char	*username;

	username = "";
	if (ft_find_envlist("USER"))
		username = ft_find_envlist("USER")->value;
	user = ft_gc_strjoin(ft_gc_strjoin(RED_COLOR, username), RESET_COLOR);
	colored_part = "mini\e[36mShell\033[0m \033[0;31m$\033[0m> ";
	command_prompt = ft_gc_strjoin(ft_gc_strjoin(user, "@"), colored_part);
	return (command_prompt);
}