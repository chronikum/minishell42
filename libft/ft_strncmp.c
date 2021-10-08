/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:38:41 by olgerret          #+#    #+#             */
/*   Updated: 2021/10/08 08:42:02 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns one if one of the strings is empty. The difference will be
**	written in int indicator (ind) pointer. This fixes a bug where
**	the function would segfault when receiving an empty string.
*/
static int	ft_check_null_strings(const char *s1, const char *s2, int *ind)
{
	if (!s1 && !s2)
	{
		(*ind) = 0;
		return (1);
	}
	if (!s1)
	{
		(*ind) = 1;
		return (1);
	}
	if (!s2)
	{
		(*ind) = -1;
		return (1);
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			i;
	int				checker[0];

	if (ft_check_null_strings(s1, s2, checker))
		return ((*checker));
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while ((ps1[i] != '\0' || ps2[i] != '\0') && i < n)
	{
		if (ps1[i] != ps2[i])
		{
			if (ps1[i] < ps2[i])
				return (ps1[i] - ps2[i]);
			else
				return (ps1[i] + ps2[i]);
		}
		i++;
	}
	return (0);
}
