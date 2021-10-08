/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:17:29 by olgerret          #+#    #+#             */
/*   Updated: 2021/06/24 10:07:35 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dst == 0 || src == 0)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0')
		i++;
	while (src[j] != '\0' && j < (dstsize - 1))
	{
		if (dstsize == 0)
			return (i);
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
