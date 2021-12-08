/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:39:33 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/08 09:21:03 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **src, size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (!dst)
	{
		free((*src));
		return (NULL);
	}
	if (!(*src))
	{
		free(dst);
		return (NULL);
	}
	ft_memmove(dst, (*src), size);
	free((*src));
	(*src) = NULL;
	return (dst);
}
