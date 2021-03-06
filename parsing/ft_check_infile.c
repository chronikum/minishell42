/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_infile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:44 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:46 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

static void	ft_add_infile(t_command *command, char *command_section)
{
	char	*file_name;

	file_name = ft_get_cmd_filename(command, command_section);
	command->out_flag = -1;
	command->in_flag = IN;
	command->files = ft_new_file(file_name, file_name, 0, 0);
}

/*
	Returns the infile command if the command has an infile
*/
t_command	*ft_check_infile(t_command *command, char *command_section)
{
	if (command_section[0] == '<' && command_section[1] != '<')
	{
		command->in_flag = IN;
		command->out_flag = 0;
		ft_add_infile(command, command_section);
		command->builtin_sys_flag = SKIP;
		if (command->args)
			ft_set_builtin_flag(command);
		return (command);
	}
	else
		return (NULL);
}
