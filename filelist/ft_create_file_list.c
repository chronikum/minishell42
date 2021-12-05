/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_file_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:28:37 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/05 14:45:18 by jfritz           ###   ########.fr       */
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

/*
	Creates a new file list with given values
	char *filename
	char *full_filename
	int in
	int out
*/
t_files	*ft_new_file(char *filename, char *path, int in, int out)
{
	t_files	*new;

	new = ft_malloc(sizeof(t_files));
	new->file_name = filename;
	new->path = path;
	new->in = in;
	new->out = out;
	new->is_multiple = 0;
	new->next = NULL;
	new->is_last = 0;
	return (new);
}

/*
	Creates a file list depening on the command char array input
*/
t_files	*ft_create_file_list(char *com)
{
	char		**result;
	int			i;
	t_files		*files;
	t_files		*start;
	char		*ft_file_str;

	i = 1;
	start = NULL;
	files = NULL;
	ft_file_str = ft_substr(com, ft_strlen_not_any_quoted(com, "<>"),
			ft_strlen(com) - ft_strlen_not_any_quoted(com, "<>"));
	result = ft_file_splitter(ft_file_str, "<>");
	if (!result)
		return (NULL);
	while (result[i])
	{
		if (files)
		{
			files->next = ft_new_file(result[i], result[i], 0, 0);
			files = files->next;
		}
		else
		{
			files = ft_new_file(result[i], result[i], 0, 0);
			files->is_multiple = !!(ft_detect_mredirections(com) - 1);
			files->is_last = 0;
			start = files;
		}
		i++;
	}
	files->is_last = 1;
	if (files->is_last)
		return (start);
	return (start->next);
}
