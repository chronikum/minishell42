/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:47:51 by olgerret          #+#    #+#             */
/*   Updated: 2021/06/23 15:07:38 by olgerret         ###   ########.fr       */
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
