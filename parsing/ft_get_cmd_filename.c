/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_filename.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:36 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:37 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Gets the filename after a < or > or >> operation.
	Skips whitespaces at the beginning if there are and
	then goes until it finds the end of the string
	or a new whitespace or seperator sign.
*/
char	*ft_get_cmd_filename(t_command *command, char *cmd)
{
	char	*filename;
	char	**tmp;

	filename = NULL;
	tmp = ft_gc_split(ft_gc_strtrim(ft_gc_substr(
					cmd, 1, ft_strlen(cmd) - 1), " "), ' ');
	if (tmp[0])
		filename = ft_gc_strtrim(tmp[0], "<");
	if (tmp[1])
		command->args = &tmp[1];
	else
		command->out_flag = OUT;
	return (filename);
}
