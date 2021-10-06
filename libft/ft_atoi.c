/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:12:20 by olgerret          #+#    #+#             */
/*   Updated: 2021/06/18 17:20:54 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_sign(const char *str)
{
	if (ft_strnstr(str, "++", ft_strlen(str)) != 0
		|| (ft_strnstr(str, "--", ft_strlen(str)) != 0)
		|| (ft_strnstr(str, "+-", ft_strlen(str)) != 0)
		|| (ft_strnstr(str, "-+", ft_strlen(str)) != 0))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		negative;

	i = 0;
	result = 0;
	negative = 1;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		if (number_sign(str) == 1)
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * negative);
}
