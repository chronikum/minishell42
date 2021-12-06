/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_code_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:04:51 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:04:52 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

void	ft_strinc_exitcode_aux(char *command, t_exit_code_aux *h)
{
	ft_strncat(h->result, &command[h->i], 1);
	h->total++;
	ft_incs_uihand(command, &h->i, &h->quote_closed);
}
