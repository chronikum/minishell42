/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:38:02 by olgerret          #+#    #+#             */
/*   Updated: 2021/06/24 12:30:00 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ps;

	i = 0;
	ps = (char *)s;
	if (c == '\0')
		return (&ps[ft_strlen(ps)]);
	while (s[i] != '\0')
	{
		if (ps[i] == (char)c)
			return (&ps[i]);
		i++;
	}
	return (0);
}
