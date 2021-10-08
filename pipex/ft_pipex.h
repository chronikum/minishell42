/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:55:22 by olgerret          #+#    #+#             */
/*   Updated: 2021/10/08 13:52:45 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_pipes
{
	int		in;
	int		cmnd_count;

	int		pipe[2];
	int		temp_fd;
}			t_pipes;

typedef struct s_child
{
	int		i;
	int		out;
	char	*full_path;
	char	*temp;
	char	**cmnd;
	char	**paths;
}			t_child;

typedef struct s_parent
{
	int		i;
	int		out;
	int		argc_process;
	int		argc_parent;
	char	*full_path;
	char	*temp;
	char	**cmnd;
	char	**paths;
}			t_parent;

int		main(int argc, char **argv, char **envp);

void	cutlery(t_pipes *p, t_parent *prnt, char **argv, char **envp);
void	cutlery_dup(t_pipes *p);
void	cutlery_close(t_pipes *p, t_parent *prnt);
int		child(t_pipes *p, char **argv, char **envp);

int		parent(t_pipes *p, t_parent *prnt, char **argv, char **envp);
void	ft_open_out(t_parent *prnt, char **argv);
void	ft_double_dub(t_pipes *p, int out);

char	**path_finder(char **envp);
int		check_file(char *filename, char RW);
int		ft_array_len(char **argv);
void	command_not_found(char **argv, char CP);

void	ft_single_free(char **string);
void	ft_double_free(char	**string);
void	ft_custom_free(char **str1, char **str2, char SD);

#endif
