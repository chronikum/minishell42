/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:47:51 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/08 09:21:58 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*result;

	result = malloc(count * size);
	if (result == 0)
		return (0);
	i = 0;
	while (i < (count * size))
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}
