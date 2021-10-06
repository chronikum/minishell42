/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:22:32 by olgerret          #+#    #+#             */
/*   Updated: 2021/06/24 12:09:59 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ps;
	int		i;

	ps = (char *)s;
	i = (int)ft_strlen(ps) - 1;
	if (c == '\0')
		return (&ps[ft_strlen(ps)]);
	while (i >= 0)
	{
		if (ps[i] == (char)c)
			return (&ps[i]);
		i--;
	}
	return (0);
}
