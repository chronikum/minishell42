/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toggle_double_quote.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:19 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:20 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

void	ft_single_double_quote_handler(char *cmd, int *i, int *dq, int *sq)
{
	if (cmd[(*i)] == '\'')
		ft_toggle_quote(sq);
	if (cmd[(*i)] == '"')
		ft_toggle_quote(dq);
	(*i)++;
}

void	ft_usdq_handler(char *cmd, unsigned int *i, int *dq, int *sq)
{
	if (cmd[(*i)] == '\'')
		ft_toggle_quote(sq);
	if (cmd[(*i)] == '"')
		ft_toggle_quote(dq);
	(*i)++;
}
