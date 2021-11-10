#include "../includes/ft_minishell.h"

/*
	Returns the env list is available.
	Returns NULL if key does not exist
*/
t_envlist	*ft_find_envlist(char *key)
{
	t_envlist	*temp;

	temp = ft_env_list(NULL);
	while (temp)
	{
		if (ft_strcmp(temp->var_name, key) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
