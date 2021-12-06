/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_splitter_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:40 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:41 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

t_fs_aux	*ft_new_split_aux(char *cmd)
{
	t_fs_aux	*fs_aux;

	fs_aux = ft_malloc(sizeof(t_fs_aux));
	fs_aux->quote_closed = 1;
	fs_aux->quote_counter = 0;
	fs_aux->temp = ft_strtrim(cmd, " ");
	return (fs_aux);
}

char	*ft_return_cq_filename(t_fs_aux *fx, unsigned int *i,
		char *set, unsigned int saved)
{
	ft_fs_skip_until_notinset(fx, i, set);
	return (ft_gc_strtrim(ft_gc_substr(fx->temp,
				saved, ft_strlen_set(&fx->temp[saved], set)), " "));
}
