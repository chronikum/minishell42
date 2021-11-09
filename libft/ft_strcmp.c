#include "../includes/ft_minishell.h"

/*
	Compares string, returns zero if they are same
*/
int ft_strcmp(char *s1, char *s2)
{
	int	i;
	i = 0;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
				return (s1[i] - s2[i]);
			else
				return (s1[i] + s2[i]);
		}
		i++;
	}
	return (0);
}