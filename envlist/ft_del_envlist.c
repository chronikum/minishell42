#include "../includes/ft_minishell.h"

/*
	Delete envlist with given key and links
	the previous node to the next

	Returns one if it succeed
*/
int	ft_del_envlist(char *key_to_delete)
{
	t_envlist	*temp;
	t_envlist	*previous;

	previous = NULL;
	temp = ft_env_list(NULL);
	while (temp)
	{
		if (ft_strcmp(temp->var_name, key_to_delete) == 0)
		{
			if (previous)
				previous->next = ft_gc_memdup(temp->next, sizeof (t_envlist *));
			else
				ft_env_list(ft_env_list(NULL)->next);
			return (1);
		}
		else
		{
			previous = temp;
			temp = temp->next;
		}
	}
	return (0);
}
