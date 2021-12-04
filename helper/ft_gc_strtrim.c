/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_strtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:29:52 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 18:34:22 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gc_functions.h"

static int	ft_is_inset(char c, char const *set)
{
	int	count;

	count = 0;
	while (set[count])
	{
		if (c == set[count])
			return (1);
		count++;
	}
	return (0);
}

char	*ft_gc_strtrim(char const *s1, char const *set)
{
	unsigned int	l;
	int				start;
	int				end;
	char			*r;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return ((char *) s1);
	end = ft_strlen(s1);
	start = 0;
	l = ft_strlen(s1);
	if (ft_strlen(set) == 0)
		return (ft_gc_strdup(s1));
	while (ft_is_inset(s1[start], set) == 1)
	{
		start++;
		l--;
	}
	while (ft_is_inset(s1[end - 1], set) == 1)
	{
		end--;
		l--;
	}
	return (ft_substr(s1, start, l));
}
