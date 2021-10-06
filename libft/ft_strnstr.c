/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:26:02 by olgerret          #+#    #+#             */
/*   Updated: 2021/06/21 12:14:41 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;
	char	*phaystack;

	i = 0;
	j = 0;
	needle_len = ft_strlen(needle);
	phaystack = (char *)haystack;
	if (needle[0] == '\0')
		return (phaystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j]
			&& needle[j] != '\0' && (i + j) < len)
		{
			j++;
			if (j == needle_len)
				return (&phaystack[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
