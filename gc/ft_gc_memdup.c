/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_memdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:02:03 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/08 09:21:34 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_garbage_collector.h"

void	*ft_gc_memdup(const void *mem, size_t size)
{
	void	*dst;

	if (!mem)
		return (NULL);
	dst = malloc(size);
	if (dst != NULL)
		ft_memcpy(dst, mem, size);
	return (dst);
}
