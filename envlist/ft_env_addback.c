#include "../includes/ft_minishell.h"

void	ft_env_addback(t_envlist **lst, t_envlist *new)
{
	t_envlist	*temp;

	temp = *lst;
	if (!new)
		return ;
	if (!temp)
	{
		*lst = new;
		return ;
	}
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new;
}
