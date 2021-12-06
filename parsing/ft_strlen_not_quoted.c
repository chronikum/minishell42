/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_not_quoted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:25 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:26 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Returns the length of the current position
	until we meet a character in the set.
	This is being used to as example find < in
	a not quoted part of a string and get the
	distance to it.
*/
int	ft_strlen_not_quoted(char *str, char const *set)
{
	int	count;
	int	quote_closed;

	count = 0;
	quote_closed = 1;
	while (str[count])
	{
		if (ft_single_inset(str[count], set) != -1 && quote_closed)
			return (count);
		ft_increase_i_quote_handler(str, &count, &quote_closed);
	}
	return (count);
}
