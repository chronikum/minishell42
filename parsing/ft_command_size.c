/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:43 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:44 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

int	ft_command_size(t_command *lst)
{
	int			i;
	t_command	*temp;

	i = 1;
	temp = lst;
	if (lst == 0)
		return (0);
	while (temp->next != 0)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
