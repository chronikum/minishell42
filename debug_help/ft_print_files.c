/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:44:47 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/22 13:45:51 by olgerret         ###   ########.fr       */
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
	while (tmp)
	{
		printf("	%s( FILE )%s			|%s|\n",
			YELLOW_COLOR, RESET_COLOR, tmp->file_name);
		tmp = tmp->next;
	}
}
