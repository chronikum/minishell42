/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:38:57 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/22 13:38:58 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, char *str2, size_t n)
{
	int	i;
	int	j;

	i = -1;
	j = (int) ft_strlen(str1);
	while ((*(str2 + ++i)) && i < (int) n)
	{
		str1[j] = str2[i];
		j++;
	}
	str1[j] = '\0';
	return (str1);
}
