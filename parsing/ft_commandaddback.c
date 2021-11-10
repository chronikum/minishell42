#include "../includes/ft_minishell.h"

/*
	Appends the command to the existing command
	list or handles input null by setting the command list
	correctly
*/
t_command	*ft_commandaddback(t_command **lst, t_command *new)
{
	t_command	*temp;

	temp = *lst;
	if (!new)
		return (NULL);
	if (!temp)
	{
		*lst = new;
		return ((*lst));
	}
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new;
	return ((*lst));
}
