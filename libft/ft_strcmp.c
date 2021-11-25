/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:52:13 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/25 20:48:15 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Compares string, returns zero if they are same
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
				return (s1[i] - s2[i]);
			else
				return (s1[i] + s2[i]);
		}
		i++;
	}
	return (0);
}
