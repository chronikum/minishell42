/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:55:21 by olgerret          #+#    #+#             */
/*   Updated: 2021/09/13 13:12:56 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	check_file(char *filename, char RW)
{
	if (RW == 'W')
	{
		if (access(filename, W_OK) == -1)
		{
			ft_putstr_fd("permission denied ", 2);
			ft_putendl_fd(filename, 2);
			return (-1);
		}
	}
	else if (RW == 'R')
	{
		if (access(filename, F_OK) == -1)
		{
			ft_putstr_fd("no such file or directory: ", 2);
			ft_putendl_fd(filename, 2);
			return (-1);
		}
		else if (access(filename, R_OK) == -1)
		{
			ft_putstr_fd("permission denied ", 2);
			ft_putendl_fd(filename, 2);
			return (-1);
		}
	}
	return (0);
}

char	**path_finder(char **envp)
{
	int		i;
	char	*temp;
	char	**paths;

	i = 0;
	while (envp[i] != '\0')
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H')
		{
			temp = ft_substr(envp[i], 5, (ft_strlen(envp[i]) - 5));
			paths = ft_split(temp, ':');
			free(temp);
		}
		i++;
	}
	return (paths);
}

int	ft_array_len(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
		i++;
	return (i);
}

void	command_not_found(char **argv, char CP)
{
	if (CP == 'C')
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(argv[2], 2);
	}
	if (CP == 'P')
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(argv[3], 2);
	}
}
