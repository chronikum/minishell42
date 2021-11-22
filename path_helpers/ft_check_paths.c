/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:04:04 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/22 14:08:07 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Joins path and slash and executable name and returns string
*/
char	*ft_join_path(char *path, char *executable)
{
	char	*pathwithslash;
	char	*pathwithslashandexecutable;

	pathwithslash = ft_strjoin(path, "/");
	pathwithslashandexecutable = ft_strjoin(pathwithslash, executable);
	return (pathwithslashandexecutable);
}

/*
	Gets the executable path
*/
char	*ft_find_executable_path(char *exec)
{
	char		**paths;
	int			i;
	char		*temp_path;
	t_envlist	*env_list;

	i = 0;
	env_list = ft_find_envlist("PATH");
	if (env_list)
	{
		if (env_list->value)
		{
			paths = ft_split(env_list->value, ':');
			while (paths[i++])
			{
				temp_path = ft_join_path(paths[i], exec);
				if (access(temp_path, F_OK) != -1)
				{
					ft_double_free(paths);
					paths = NULL;
					return (temp_path);
				}
			}		
		}
	}
	return (NULL);
}

/*
	Checks if a command exists in the given path variable
*/
int	ft_check_command(char *exec)
{
	char	**paths;
	int		i;
	char	*temp_path;

	i = 0;
	paths = ft_split(getenv("PATH"), ':');
	while (paths[i])
	{
		temp_path = ft_join_path(paths[i], exec);
		if (access(temp_path, F_OK) != -1)
		{
			free(temp_path);
			ft_double_free(paths);
			return (1);
		}
		i++;
	}
	free(temp_path);
	ft_double_free(paths);
	printf("urgent: command not found: %s\n", exec);
	return (-1);
}
