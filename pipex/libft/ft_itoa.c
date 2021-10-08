/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:56:45 by olgerret          #+#    #+#             */
/*   Updated: 2021/06/28 09:15:23 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_counter(int n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		counter++;
		n *= -1;
	}
	if (n == 0)
		counter++;
	while (n > 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

static char	*minimum_value(void)
{
	char	*result;

	result = (char *)malloc(12 * sizeof(char));
	if (result == 0)
		return (0);
	result[0] = '-';
	result[1] = '2';
	result[2] = '1';
	result[3] = '4';
	result[4] = '7';
	result[5] = '4';
	result[6] = '8';
	result[7] = '3';
	result[8] = '6';
	result[9] = '4';
	result[10] = '8';
	result[11] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		int_len;

	if (n == -2147483648)
		return (minimum_value());
	int_len = int_counter(n);
	result = (char *)malloc((int_len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	if (n == 0)
		result[0] = '0';
	while (n > 0)
	{
		result[int_len - 1 - i++] = ((n % 10) + '0');
		n /= 10;
	}
	result[int_len] = '\0';
	return (result);
}
