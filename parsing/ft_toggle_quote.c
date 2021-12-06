/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toggle_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:18 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:19 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Increases counter by one and toggles quote counter if it encounters one
*/
void	ft_increase_i_quote_handler(char *cmd, int *i, int *quote)
{
	if (cmd[(*i)] == '"')
		ft_toggle_quote(quote);
	(*i)++;
}

/*
Gets called when a quote is being seen. Toggles a int (pointer)
*/
void	ft_toggle_quote(int *quote_toggle)
{
	if ((*quote_toggle))
		(*quote_toggle) = 0;
	else
		(*quote_toggle) = 1;
}

/*
	Increases counter by one and toggles quote counter if it encounters one
*/
void	ft_inc_uqh(char *cmd, unsigned int *i, int *quote)
{
	if (cmd[(*i)] == '"')
		ft_toggle_quote(quote);
	(*i)++;
}

/*
	Toggles if it sees a single quote at the current zero index
*/
void	ft_singlequote_handler(char *cmd, int *quote)
{
	if (cmd[0] == '\'')
		ft_toggle_quote(quote);
}
