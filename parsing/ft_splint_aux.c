/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splint_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:29 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:30 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

int	ft_increase_until_change(int *q1, int *q2, int *q3, char *temp)
{
	unsigned int	i;

	i = 0;
	while (!(*q1) || !(*q2))
	{
		(*q3)++;
		ft_usdq_handler(temp, &i, q1, q2);
	}
	return (i);
}

/*
	Adds offset until it meets the quote end
	to return the whole string afterwards
*/
char	*ft_increase_and_return_quote(t_gnw_splint *gnw,
		unsigned int *i, unsigned int *saved)
{
	ft_usdq_handler(gnw->temp, i, &gnw->q[0], &gnw->q[1]);
	(*i) += ft_increase_until_change(&gnw->q[0],
			&gnw->q[1], &gnw->q[2], &gnw->temp[(*i)]);
	return (ft_gc_strtrim(ft_gc_substr(gnw->temp,
				(*saved), (gnw->q[2] + 1)), " "));
}
