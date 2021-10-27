#include "../includes/ft_minishell.h"

void	ft_print_env()
{
	t_envlist *env_list;

	env_list = ft_env_list(NULL);
	while (env_list)
	{
		printf("%s\n", env_list->full_line);
		env_list = env_list->next;
	}
}

/*
** @TODO
*/
int	ft_env(void)
{
	ft_print_env();
	return (1);
}

