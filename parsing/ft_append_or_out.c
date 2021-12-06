/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_or_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:45 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:46 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Returns append or out indicator
*/
int	ft_append_or_out(t_command *command)
{
	int		append;
	int		out;
	char	*reversed;

	reversed = ft_gc_strrev(command->original_string);
	command->out_flag = OUT;
	append = ft_strnstr_now_quotes_pos(reversed, ">>",
			ft_strlen(reversed));
	out = ft_strnstr_now_quotes_pos(reversed, ">",
			ft_strlen(reversed));
	if (out == append && (!!append && !!out))
		command->out_flag = APPEND;
	return (command->out_flag);
}
