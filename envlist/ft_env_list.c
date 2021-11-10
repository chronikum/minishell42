#include "../includes/ft_minishell.h"

t_envlist	*ft_env_list(t_envlist *env_list)
{
	static t_envlist	*list;

	if (env_list)
		list = env_list;
	return (list);
}
