/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newcommand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:34 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:35 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Initiates a new command with ONLY
	the command value filled.
*/
t_command	*ft_newcommand(char *command)
{
	t_command	*result;

	result = (t_command *)malloc(sizeof(t_command));
	if (result == 0)
		return (0);
	result->original_string = command;
	result->command = command;
	result->next = NULL;
	result->args = NULL;
	result->file = NULL;
	result->delimiter = NULL;
	result->op = -3301;
	result->in_flag = -1;
	result->out_flag = -3301;
	result->builtin_sys_flag = -3301;
	result->files = NULL;
	return (result);
}
