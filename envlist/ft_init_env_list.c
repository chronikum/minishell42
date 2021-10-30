#include "../includes/ft_minishell.h"

size_t ft_get_env_count(char **envp)
{
	size_t i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

t_envlist *ft_new_list(char *f, char *n, char *c, char **envp)
{
	t_envlist *new;
	new = ft_malloc(sizeof(t_envlist));
	new->full_line = f;
	new->var_name = n;
	new->value = c;
	new->envp = envp;
	return (new);
}

/*
	Creates the environment linked list
*/
t_envlist	*ft_create_env_list(char **envp)
{
	t_envlist *env_list;
	t_envlist *start;
	size_t i;
	char *command;
	char **command_split;

	i = 0;
	while (ft_get_env_count(envp) > i)
	{
		command = envp[i];
		command_split = ft_split(envp[i], '=');
		if (!env_list)
		{
			env_list = ft_new_list(command, command_split[0], command_split[1], envp);
			start = env_list;
		}
		else
		{
			env_list->next = ft_new_list(command, command_split[0], command_split[1], envp);
			env_list = env_list->next;
		}
		free(command_split);
		i++;
	}
	return (start);
}