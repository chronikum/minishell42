/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtouppercase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:29:35 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 17:29:36 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_gc_functions.h"
#include "../../libft/libft.h"

char	*ft_strtouppercase(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_gc_strdup(str);
	while (temp[i])
	{
		temp[i] = ft_toupper(temp[i]);
		i++;
	}
	return (temp);
}
