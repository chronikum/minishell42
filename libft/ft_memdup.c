/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:22:00 by jfritz            #+#    #+#             */
/*   Updated: 2021/12/08 09:21:46 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *mem, size_t size)
{
	void	*dst;

	if (!mem)
		return (NULL);
	dst = malloc(size);
	if (dst != NULL)
		ft_memcpy(dst, mem, size);
	return (dst);
}
