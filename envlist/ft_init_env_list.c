/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:28:10 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/05 12:07:34 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

size_t	ft_get_env_count(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

/*
	Creates a new env list with the given
	full line	(full line)
	n			(name)
	c			(value)
	envp		(envp char array)
*/
t_envlist	*ft_new_list(char *f, char *n, char *c, char **envp)
{
	t_envlist	*new;

	new = ft_malloc(sizeof(t_envlist));
	new->full_line = f;
	new->var_name = n;
	new->value = c;
	new->envp = envp;
	new->next = NULL;
	return (new);
}

/*
	Appends to the list or creates it
*/
void	ft_append_to_list(char *command,
		char **c_spl, char **envp, t_envlist **env_list)
{
	(*env_list)->next = ft_new_list(command, c_spl[0], c_spl[1], envp);
	(*env_list) = (*env_list)->next;
}

/*
	Creates the environment linked list
*/
t_envlist	*ft_create_env_list(char **envp)
{
	t_envlist	*env_list;
	t_envlist	*start;
	size_t		i;
	char		*command;
	char		**c_spl;

	env_list = NULL;
	start = NULL;
	i = 0;
	while (ft_get_env_count(envp) > i)
	{
		command = envp[i];
		c_spl = ft_gc_split(envp[i], '=');
		if (!env_list)
		{
			env_list = ft_new_list(command, c_spl[0], c_spl[1], envp);
			start = env_list;
		}
		else
			ft_append_to_list(command, c_spl, envp, &env_list);
		i++;
	}
	return (start);
}
