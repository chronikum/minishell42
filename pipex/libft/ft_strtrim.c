/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:31:58 by olgerret          #+#    #+#             */
/*   Updated: 2021/06/29 16:03:22 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	set_iterator(char const s, char const *set)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s)
			counter++;
		i++;
	}
	return (counter);
}

static size_t	s1_right(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > 0)
	{
		if (set_iterator(s1[i - 1], set) == 0)
			return (i);
		i--;
	}
	return (0);
}

static size_t	s1_left(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (set_iterator(s1[i], set) == 0)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		left;
	size_t		right;
	size_t		result_len;
	size_t		i;
	char		*result;

	if (s1 == 0 || set == 0)
		return (0);
	left = s1_left(s1, set);
	right = s1_right(s1, set);
	result_len = right - left;
	result = (char *)malloc((result_len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	while (i < result_len)
	{
		result[i] = s1[left + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
