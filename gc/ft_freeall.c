/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:02:02 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/22 14:02:03 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_garbage_collector.h"

/*
	Frees all pointers ever allocated by ft_malloc.
	This should be called when the program ends.
*/
void	ft_freeall(void)
{
	t_pointer	*start;
	t_pointer	addrs_cumulated;
	t_pointer	tmp;

	start = ft_gclststart(NULL);
	addrs_cumulated = start[0];
	while (addrs_cumulated)
	{
		tmp = addrs_cumulated;
		addrs_cumulated = (*(t_pointer *) addrs_cumulated);
		free(tmp);
	}
	(*start) = NULL;
}
