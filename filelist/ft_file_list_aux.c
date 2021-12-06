/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_list_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:08:19 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:08:20 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

int	ft_file_count(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

void	ft_fs_skip_to_quote_end(t_fs_aux *fs_aux, unsigned int *i)
{
	ft_inc_uqh(fs_aux->temp, i, &fs_aux->quote_closed);
	while (!fs_aux->quote_closed)
	{
		fs_aux->quote_counter++;
		ft_inc_uqh(fs_aux->temp, i, &fs_aux->quote_closed);
	}
}

void	ft_fs_skip_until_notinset(t_fs_aux *fs_aux,
		unsigned int *i, char *set)
{
	while ((ft_single_inset(fs_aux->temp[(*i)],
				set) != -1) && fs_aux->temp[(*i)])
		ft_inc_uqh(fs_aux->temp, i, &fs_aux->quote_closed);
}

/*
	Returns the return value. Also handles it if no files
	are present at all (delimiter missing)
*/
t_files	*ft_filelist_returnval(t_files *start, t_files *files)
{
	if (!files)
		return (NULL);
	files->is_last = 1;
	if (files->is_last)
		return (start);
	return (start->next);
}
