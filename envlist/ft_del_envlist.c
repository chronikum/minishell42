#include "../includes/ft_minishell.h"

/*
	Delete envlist with given key and links
	the previous node to the next

	Returns one if it succeed
*/
int	ft_del_envlist(char *key_to_delete)
{
	t_envlist	*temp;

	temp = ft_env_list(NULL);
	while (temp)
	{
		if (ft_strcmp(temp->var_name, key_to_delete) == 0)
		{
			temp->var_name = NULL;
			temp->value = NULL;
			temp->full_line = NULL;
		}
		temp = temp->next;
	}
	return (0);
}
