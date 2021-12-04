/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:28:05 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 17:28:06 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

void	ft_env_addback(t_envlist **lst, t_envlist *new)
{
	t_envlist	*temp;

	temp = *lst;
	if (!new)
		return ;
	if (!temp)
	{
		*lst = new;
		return ;
	}
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new;
}
