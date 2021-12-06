/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:04:35 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:04:36 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Helper function for translate env, appending a new
	char and increasing both total char count and
	iterator through the existing string
*/
void	ft_strncincrtotaluihand(char *command, t_envit *h)
{
	ft_strncat(h->result, &command[h->i], 1);
	h->total++;
	ft_incs_uihand(command, &h->i, &h->qclosed);
}
