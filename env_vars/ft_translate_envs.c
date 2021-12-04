/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_envs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:27:51 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 19:11:36 by jfritz           ###   ########.fr       */
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
		ft_single_increase_i_quote_handler(command, &i, &quote_closed);
		total++;
	}
	return (total);
}

char	*ft_translate_envs(char *command)
{
	unsigned int	i;
	int				quote_closed;
	char			*var_name;
	char			*result;
	int				total;

	result = malloc(sizeof(char) * ft_total_count(command) + 1);
	i = 0;
	total = 0;
	quote_closed = 1;
	while (command[i])
	{
		if (command[i] == '$' && command[i + 1] && quote_closed)
		{
			var_name = ft_genvval(ft_substr(command, i,
						ft_strlen_set(&command[i], " |><\"'+-")));
			ft_strncat(result, var_name, ft_strlen(var_name));
			total += ft_strlen(var_name);
			i += ft_strlen_set(&command[i], " |><\"'+-");
		}
		else if (quote_closed)
		{
			ft_strncat(result, &command[i], 1);
			total++;
			ft_incs_uihand(command, &i, &quote_closed);
		}
		else
		{
			while (!quote_closed)
			{
				ft_strncat(result, &command[i], 1);
				total++;
				ft_incs_uihand(command, &i, &quote_closed);
			}
		}
	}
	result[total] = '\0';
	return (result);
}
