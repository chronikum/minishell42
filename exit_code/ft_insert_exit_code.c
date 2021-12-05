/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_exit_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:28:18 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/05 14:02:00 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Increases counter by one and toggles quote counter if it encounters one
*/
static void	ft_single_increase_i_quote_handler(char *cmd,
	unsigned int *i, int *quote)
{
	if (cmd[(*i)] == '\'')
		ft_toggle_quote(quote);
	(*i)++;
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
		if (command[i] == '$' && command[i + 1] == '?' && quote_closed)
		{
			var_name = ft_itoa(ft_set_most_recent_exit_code(0, 0));
			i += ft_strlen_set(&command[i], " |><+-\"");
			total += (int)ft_strlen(var_name);
		}
		ft_single_increase_i_quote_handler(command, &i, &quote_closed);
		total++;
	}
	return (total);
}

char	*ft_insert_exit_code(char *command)
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
		if (command[i] == '$' && command[i + 1] == '?' && quote_closed)
		{
			var_name = ft_itoa(ft_set_most_recent_exit_code(0, 0));
			ft_strncat(result, var_name, ft_strlen(var_name));
			total += ft_strlen(var_name);
			i += ft_strlen_set(&command[i], " |><\"+-");
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
				ft_single_increase_i_quote_handler(command, &i, &quote_closed);
			}
		}
	}
	result[total] = '\0';
	return (result);
}