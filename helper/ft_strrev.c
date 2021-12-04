#include "../includes/ft_minishell.h"

int	ft_strlen_int(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
	Reverses a string and null terminates it afterwards
*/
char *ft_gc_strrev(char *str)
{
	char	*newstr;
	int		i;
	int		j;
	
	i = 0;
	j = ft_strlen_int(str);
	newstr = ft_malloc(sizeof(char) * ft_strlen_int(str) + 1);
	while (j != -1)
	{
		if (str[j] != '\0')
		{
			newstr[i] = str[j];
			i++;
		}
		j--;
	}
	newstr[i] = '\0';
	return (newstr);
}