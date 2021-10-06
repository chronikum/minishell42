/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:46:03 by olgerret          #+#    #+#             */
/*   Updated: 2021/06/19 13:30:20 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
		return (dst);
	}
	i = len;
	while (i > 0)
	{
		pdst[i - 1] = psrc[i - 1];
		i--;
	}
	return (dst);
}
