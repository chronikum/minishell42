/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_calloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:59:24 by jfritz            #+#    #+#             */
/*   Updated: 2021/12/08 09:59:40 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

void	*ft_gc_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*result;

	result = ft_malloc(count * size);
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
