/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:33 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:34 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Returns the length until it meets the character specified
	or a null terminator.
	Returns -1 if none of both is being found.
*/
int	ft_strlenc(char *cmd, char c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!cmd[i] && i == 0)
			return (-1);
		if (!cmd[i] && i != 0)
			return (i);
		if (cmd[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
	Returns the length until it meets the a character specified
	in the set or a null terminator.
	Returns -1 if none of those is being found.
*/
int	ft_strlen_set(char *cmd, char *set)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!cmd[i] && i == 0)
			return (-1);
		if (!cmd[i] && i != 0)
			return (i);
		if (ft_single_inset(cmd[i], set) != -1 && i != 0)
			return (i);
		i++;
	}
	return (-1);
}
