/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:41:51 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/22 13:41:52 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

int	ft_cd(t_command *command)
{
	char		*path;
	t_envlist	*env_list;

	if (!command->args[1])
	{
		env_list = ft_find_envlist("HOME");
		if (ft_strlen(env_list->value) != 0)
			path = env_list->value;
		else
		{
			printf("HOME is not being set \n");
			return (1);
		}
	}
	else
		path = command->args[1];
	ft_setenv("PWD", path);
	if (chdir(path) == -1)
	{
		if (access(path, F_OK) == -1)
			printf("bash: cd: %s: No such file or directory\n", path);
		else
			printf("bash: cd: %s: Not a directory\n", path);
	}
	return (0);
}
