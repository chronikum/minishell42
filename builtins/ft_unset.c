/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:42:06 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/22 13:42:09 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Unsets a env variable
*/
int	ft_unset(t_command *command)
{
	if (command->args[1])
		return (ft_del_envlist(command->args[1]));
	return (0);
}
