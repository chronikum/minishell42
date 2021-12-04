#include "../includes/ft_minishell.h"

void	ft_increase_until_change(int *q1, int *q2, int *q3, char *temp, unsigned int *i)
{
	while (!(*q1) || !(*q2))
	{
		(*q3)++;
		ft_u_single_double_quote_handler(temp, i, q1, q2);
	}
}