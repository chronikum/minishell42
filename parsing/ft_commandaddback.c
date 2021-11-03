#include "../includes/ft_minishell.h"

/*
	Appends the command to the existing command
	list or handles input null by setting the command list
	correctly
*/
void	ft_commandaddback(t_command **lst, t_command *new)
{
	t_command	*temp;

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