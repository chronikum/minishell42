/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:29:47 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 17:29:48 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gc_functions.h"

char	*ft_gc_strdup(const char *s1)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	result = (char *)ft_malloc((len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
