/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:03:50 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:03:53 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

void	static	ft_print_flags(t_command *command_struct)
{
	printf("	in_flag: 			%d	%s\n",
		command_struct->in_flag,
		ft_translate_flags(command_struct->in_flag));
	printf("	out_flag: 			%d	%s\n",
		command_struct->out_flag,
		ft_translate_flags(command_struct->out_flag));
	printf("	builtin_sys_flag:		%d	%s\n",
		command_struct->builtin_sys_flag,
		ft_translate_flags(command_struct->builtin_sys_flag));
	printf("%sSECTION END %s\n", BACKGROUND_BLUE, RESET_COLOR);
}

void	ft_command_debug(t_command *start)
{
	t_command	*command_struct;

	command_struct = start;
	while (command_struct)
	{
		if (DEBUG)
		{
			printf("%sSECTION     %s\n", BACKGROUND_BLUE, RESET_COLOR);
			printf("	Command: 			%s\n", command_struct->command);
			printf("	original_string: 		%s\n",
				ft_gc_strtrim(command_struct->original_string, "<>| "));
			printf("	delimiter: 			%s\n", command_struct->delimiter);
			ft_arg_printer(command_struct->args);
			if (command_struct->file)
			{
				printf("	file: 				%s|\n", command_struct->file);
				printf("	FILE PATH LENGTH : 	%lu\n",
					ft_strlen(command_struct->file));
			}
			printf("	files: 			\n");
			ft_print_files(command_struct->files);
			ft_print_flags(command_struct);
		}
		command_struct = command_struct->next;
	}
}
