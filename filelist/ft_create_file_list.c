/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_file_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:28:37 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/05 15:02:45 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

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

static	void	ft_cr_ret_next(t_files **files, char *fn, int i, int o)
{
	(*files)->next = ft_new_file(fn, fn, i, o);
	(*files) = (*files)->next;
}

static	void	ft_create_head(t_files **s, t_files **l, char *com, char *fn)
{
	(*l) = ft_new_file(fn, fn, 0, 0);
	(*l)->is_multiple = !!(ft_detect_mredirections(com) - 1);
	(*l)->is_last = 0;
	(*s) = (*l);
}

static	void	ft_init_file_lists(t_files **start, t_files **files)
{
	(*start) = NULL;
	(*files) = NULL;
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
	ft_init_file_lists(&start, &files);
	ft_file_str = ft_substr(com, ft_strlen_not_any_quoted(com, "<>"),
			ft_strlen(com) - ft_strlen_not_any_quoted(com, "<>"));
	result = ft_file_splitter(ft_file_str, "<>");
	if (!result)
		return (NULL);
	while (result[i])
	{
		if (files)
			ft_cr_ret_next(&files, result[i], 0, 0);
		else
			ft_create_head(&start, &files, com, result[i]);
		i++;
	}
	files->is_last = 1;
	if (files->is_last)
		return (start);
	return (start->next);
}
