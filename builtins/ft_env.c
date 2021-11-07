#include "../includes/ft_minishell.h"

// needs a fix :( will print null as first env for a unknown reason
void	ft_print_env()
{
	t_envlist	*temp;

	temp = ft_env_list(NULL);
	while (temp)
	{
		printf("%s\n", temp->full_line);
		temp = temp->next;
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
