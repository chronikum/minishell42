/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_exit_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:28:18 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/05 13:27:14 by jfritz           ###   ########.fr       */
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
		if (command[i] == '$' && command[i + 1] == '?' && quote_closed)
		{
			var_name = ft_itoa(ft_set_most_recent_exit_code(0, 0));
			i += ft_strlen_set(&command[i], " |><+-\"");
			total += (int)ft_strlen(var_name);
		}
		ft_incs_uihand(command, &i, &quote_closed);
		total++;
	}
	return (total);
}

t_exit_code_aux	*ft_create_exit_struct(char *command)
{
	t_exit_code_aux	*aux;
	
	aux = ft_malloc(sizeof(t_exit_code_aux));
	aux->i = 0;
	aux->quote_closed = 1;
	aux->var_name = NULL;
	aux->result = ft_malloc(sizeof(char) * ft_total_count(command) + 1);
	aux->total = 0;
	return (aux);
}

char	*ft_insert_exit_code(char *command)
{
	t_exit_code_aux	*aux;
	
	aux = ft_create_exit_struct(command);
	while (command[aux->i])
	{
		if (command[aux->i] == '$' && command[aux->i + 1] == '?' && aux->quote_closed)
		{
			aux->var_name = ft_itoa(ft_set_most_recent_exit_code(0, 0));
			ft_strncat(aux->result, aux->var_name, ft_strlen(aux->var_name));
			aux->total += ft_strlen(aux->var_name);
			aux->i += ft_strlen_set(&command[aux->i], " |><\"+-");
		}
		else if (aux->quote_closed)
		{
			ft_strncat(aux->result, &command[aux->i], 1);
			aux->total++;
			ft_incs_uihand(command, &aux->i, &aux->quote_closed);
		}
		else
		{
			while (!aux->quote_closed)
				ft_strinc_exitcode_aux(command, aux);
		}
	}
	aux->result[aux->total] = '\0';
	return (aux->result);
}
