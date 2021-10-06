/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:38:41 by olgerret          #+#    #+#             */
/*   Updated: 2021/06/25 15:26:23 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			i;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while ((ps1[i] != '\0' || ps2[i] != '\0') && i < n)
	{
		if (ps1[i] != ps2[i])
		{
			if (ps1[i] < ps2[i])
				return (ps1[i] - ps2[i]);
			else
				return (ps1[i] + ps2[i]);
		}
		i++;
	}
	return (0);
}
