/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:28 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:29 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

t_gnw_splint	*ft_new_gnw(char *cmd)
{
	t_gnw_splint	*gnw;

	gnw = ft_malloc(sizeof(t_gnw_splint));
	gnw->q[0] = 1;
	gnw->q[1] = 1;
	gnw->q[2] = 0;
	gnw->temp = ft_gc_strtrim(cmd, "| ");
	return (gnw);
}

/*
	Counts words. Can handle quotes with ease.
*/
int	ft_new_word_counter(char *cmd)
{
	unsigned int	i;
	int				quote_closed;
	int				words;
	char			*temp;
	int				single_closed;

	i = 0;
	words = 1;
	quote_closed = 1;
	single_closed = 1;
	temp = ft_gc_strtrim(cmd, "| ");
	while (temp[i])
	{
		if (temp[i] == ' ' && quote_closed && single_closed)
		{
			words++;
			while (temp[i] == ' ' && temp[i] && quote_closed && single_closed)
				ft_usdq_handler(temp, &i, &quote_closed, &single_closed);
		}
		ft_usdq_handler(temp, &i, &quote_closed, &single_closed);
	}
	return (words);
}

static void	ft_reset_static_vars(unsigned int *i, unsigned int *saved)
{
	(*saved) = 0;
	(*i) = 0;
}

char	*ft_get_next_word(char *cmd, int r)
{
	static unsigned int	saved = 0;
	static unsigned int	i = 0;
	t_gnw_splint		*gnw;

	gnw = ft_new_gnw(cmd);
	saved = i;
	if (r)
		ft_reset_static_vars(&i, &saved);
	while (gnw->temp[i])
	{
		gnw->q[2] = 0;
		if (gnw->temp[i] == '"' || gnw->temp[i] == '\'')
			return (ft_increase_and_return_quote(gnw, &i, &saved));
		if (gnw->temp[i] == ' ' && gnw->q[0] && gnw->q[1])
		{
			while (gnw->temp[i] == ' ' && gnw->temp[i])
				ft_usdq_handler(gnw->temp, &i, &gnw->q[0], &gnw->q[1]);
			return (ft_gc_strtrim(ft_gc_substr(gnw->temp,
						saved, ft_strlenc(&gnw->temp[saved], ' ')), " "));
		}
		ft_usdq_handler(gnw->temp, &i, &gnw->q[0], &gnw->q[1]);
	}
	return (ft_gc_strtrim(ft_gc_substr(gnw->temp,
				saved, ft_strlenc(&gnw->temp[saved], ' ')), " "));
}

char	**ft_splint(char *s)
{
	char	**result;
	char	*current;
	int		i;
	char	*to_use;

	i = 0;
	to_use = ft_gc_substr(s, 0, ft_strlen_not_any_quoted(s, "<>"));
	current = NULL;
	result = ft_malloc(sizeof(char *) * (ft_new_word_counter(to_use) + 1));
	while (current || i == 0)
	{
		if (!current)
			current = ft_gc_strtrim(ft_get_next_word(to_use, 1), "\"'");
		if (!current)
			return (NULL);
		if (ft_strlen(current) != 0)
		{
			result[i] = current;
			i++;
		}
		current = ft_gc_strtrim(ft_get_next_word(to_use, 0), "\"'");
	}
	result[i] = NULL;
	return (result);
}
