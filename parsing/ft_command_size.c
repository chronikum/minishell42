#include "../includes/ft_minishell.h"

int	ft_command_size(t_command *lst)
{
	int			i;
	t_command	*temp;

	i = 1;
	temp = lst;
	if (lst == 0)
		return (0);
	while (temp->next != 0)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
