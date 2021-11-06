#include "../includes/ft_minishell.h"

/*
	Returns the last command in the list
*/
t_command	*ft_get_last_command(t_command *lst)
{
	t_command	*temp;

	temp = lst;
	if (lst == 0)
		return (0);
	while (temp->next != 0)
		temp = temp->next;
	return (temp);
}
