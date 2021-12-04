#include "../includes/ft_minishell.h"

int	ft_increase_until_change(int *q1, int *q2, int *q3, char *temp)
{
	unsigned int i;
	
	i = 0;
	while (!(*q1) || !(*q2))
	{
		(*q3)++;
		ft_usdq_handler(temp, &i, q1, q2);
	}
	return (i);
}
