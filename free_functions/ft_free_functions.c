#include "../includes/ft_minishell.h"

void	ft_single_free(char **string)
{
	if (!string)
		return ;
	free(*string);
	*string = 0;
}

void	ft_double_free(char	**string)
{
	int	i;

	if (!string)
		return ;
	i = 0;
	while (string[i] != NULL)
	{
		ft_single_free(&string[i]);
		i++;
	}
	free(string);
	string = 0;
}

void	ft_triple_free(char	***string)
{
	int	i;

	if (!string)
		return ;
	i = 0;
	while (string[i] != NULL)
	{
		ft_double_free(string[i]);
		i++;
	}
	free(string);
	string = 0;
}
