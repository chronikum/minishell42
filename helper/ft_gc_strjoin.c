/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:29:50 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 17:29:51 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

char	*ft_gc_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	length;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	length = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)ft_malloc((length + 1) * sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
