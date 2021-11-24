/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:44:47 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/24 16:39:19 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Prints all the elements in a given char
	array array
*/
void	ft_print_files(t_files *files)
{
	t_files	*tmp;

	tmp = files;
	if (files)
		printf("	is multiple files:	%d\n", tmp->is_multiple);
	while (tmp)
	{
		printf("	%s( FILE )%s			|%s|\n",
			YELLOW_COLOR, RESET_COLOR, tmp->file_name);
		tmp = tmp->next;
	}
}
