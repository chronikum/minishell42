/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:00:38 by olgerret          #+#    #+#             */
/*   Updated: 2021/06/23 16:47:24 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

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
