/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_mredirections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:41 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:42 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Checks for multiple redirections and returns count of them
*/
int	ft_detect_mredirections(char *command)
{
	int	i;
	int	quote_closed;
	int	counted;

	i = 0;
	counted = 0;
	quote_closed = 1;
	while (command[i])
	{
		if (i != 0)
		{
			if (command[i - 1] == '<' && command[i] == '<')
			{
				counted++;
				ft_increase_i_quote_handler(command, &i, &quote_closed);
				continue ;
			}
		}
		if (ft_single_inset(command[i], "<>") != -1 && quote_closed)
			counted++;
		ft_increase_i_quote_handler(command, &i, &quote_closed);
	}
	return (counted);
}
