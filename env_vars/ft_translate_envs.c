/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_envs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:27:51 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/08 09:20:37 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Gets env value or an empty string
*/
static	char	*ft_genvval(char *key)
{
	t_envlist	*env;

	env = ft_find_envlist(ft_gc_strtrim(key, "$\""));
	if (env)
		return (env->value);
	return ("");
}

static	int	ft_total_count(char *command)
{
	unsigned int	i;
	int				quote_closed;
	char			*var_name;
	int				total;

	i = 0;
	quote_closed = 1;
	total = 0;
	while (command[i])
	{
		if (command[i] == '$' && quote_closed)
		{
			var_name = ft_substr(command, i,
					ft_strlen_set(&command[i], " |><+-"));
			i += ft_strlen_set(&command[i], " |><+-");
			total += (int)ft_strlen(ft_genvval(var_name));
		}
		ft_incs_uihand(command, &i, &quote_closed);
		total++;
	}
	return (total);
}

/*
	Creates a new helper struct
*/
t_envit	*ft_env_aux(char *command)
{
	t_envit	*helper;

	helper = ft_malloc(sizeof(t_envit));
	helper->i = 0;
	helper->qclosed = 1;
	helper->var_name = NULL;
	helper->result = ft_malloc(sizeof(char) * ft_total_count(command) + 1);
	helper->total = 0;
	return (helper);
}

char	*ft_translate_envs(char *command)
{
	t_envit	*h;

	h = ft_env_aux(command);
	while (command[h->i])
	{
		if (command[h->i] == '$' && command[h->i + 1] && h->qclosed)
		{
			h->var_name = ft_genvval(ft_substr(command, h->i,
						ft_strlen_set(&command[h->i], " |><\"'+-")));
			ft_strncat(h->result, h->var_name, ft_strlen(h->var_name));
			h->total += ft_strlen(h->var_name);
			h->i += ft_strlen_set(&command[h->i], " |><\"'+-");
		}
		else if (h->qclosed)
			ft_strncincrtotaluihand(command, h);
		else
		{
			while (!h->qclosed)
				ft_strncincrtotaluihand(command, h);
		}
	}
	h->result[h->total] = '\0';
	return (h->result);
}
