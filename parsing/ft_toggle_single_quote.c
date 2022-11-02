/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toggle_single_quote.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:17 by olgerret          #+#    #+#             */
/*   Updated: 2022/07/20 19:07:39 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Increases counter by one and toggles quote counter if it encounters one
*/
void	ft_increase_i_singlequote_handler(char *cmd, int *i, int *quote)
{
	if (cmd[(*i)] == '\'')
		ft_toggle_quote(quote);
	(*i)++;
}

/*
	Increases counter by one and toggles quote counter if it encounters one
	ft_increase_ui_singlequote_handler
*/
void	ft_incs_uihand(char *cmd, unsigned int *i, int *quote)
{
	if (cmd[(*i)] == '\'')
		ft_toggle_quote(quote);
	(*i)++;
}
