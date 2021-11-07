#include "../includes/ft_minishell.h"

/*
	Sets or creates a env list for the given key with the
	given value
*/
t_envlist	*ft_setenv(char *key, char *value)
{
	t_envlist	*env_list;
	char		*full_line;
	t_envlist	*start;

	if (!key || !value)
		return (NULL);
	start = ft_env_list(NULL);
	env_list = ft_find_envlist(key);
	full_line = ft_gc_strjoin(ft_gc_strjoin(key, "="), value);
	if (env_list)
	{
		env_list->value = value;
		env_list->full_line = full_line;
	}
	else
		ft_env_addback(&start, ft_new_list(full_line, key, value, ft_env_list(NULL)->envp));
	return (start);
}