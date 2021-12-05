/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_exit_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:28:18 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/05 15:53:29 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

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
			var_name = ft_itoa(ft_set_most_recent_exit_code(0, 0));
			i += ft_strlen_set(&command[i], " |><+-");
			total += (int)ft_strlen(var_name);
		}
		ft_incs_uihand(command, &i, &quote_closed);
		total++;
	}
	return (total);
}

/*
	Creates a new helper struct
*/
t_envit	*ft_env_aux2(char *command)
{
	t_envit	*helper;

	helper = ft_malloc(sizeof(t_envit));
	helper->i = 0;
	helper->qclosed = 1;
	helper->var_name = NULL;
	helper->result = malloc(sizeof(char) * ft_total_count(command) + 1);
	helper->total = 0;
	return (helper);
}

char	*ft_insert_exit_code(char *command)
{
	t_envit	*h;

	h = ft_env_aux2(command);
	while (command[h->i])
	{
		if (command[h->i] == '$' && command[h->i + 1] && h->qclosed)
		{
			h->var_name = ft_itoa(ft_set_most_recent_exit_code(0, 0));
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
