#include "../includes/ft_minishell.h"


/*
	Exports a value and a key.
	Returns 0 on success and 1 if something goes wrong
	Checks if the key or value are valid numbers
*/
int	ft_raw_export(char *key, char *value)
{
	if (ft_strlen(key) == 0 || ft_strlen(value) == 0)
		return (1);
	if (ft_strchr(key, ' ') || ft_strchr(value, ' '))
		return (1);
	return (!ft_setenv(key, value));
}

/*
	Exports a value and a key declared in cmd command.
	Returns 0 on success and 1 if something goes wrong
*/
int	builtin_export(char *cmd)
{
	char	*key_value_pair;
	char	**splitted_parts;

	splitted_parts = ft_gc_split(cmd, ' ');
	if (splitted_parts[1])
	{
		key_value_pair = splitted_parts[1];
		if (ft_strchr(key_value_pair, '=') == ft_strrchr(key_value_pair, '=') 
		&& ft_strrchr(key_value_pair, '='))
			return (ft_raw_export(ft_gc_split(key_value_pair, '=')[0], ft_gc_split(key_value_pair, '=')[1]));
	}
	return (1);
}