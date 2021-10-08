/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:22:15 by olgerret          #+#    #+#             */
/*   Updated: 2021/08/18 16:24:03 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_single_free(char **string)
{
	if (!string)
		return ;
	free(*string);
	*string = 0;
}

void	ft_double_free(char	**string)
{
	int	i;

	i = 0;
	if (!string)
		return ;
	while (string[i] != NULL)
	{
		ft_single_free(&string[i]);
		i++;
	}
	free(string);
	string = 0;
}

void	ft_custom_free(char **str1, char **str2, char SD)
{
	if (SD == 'S')
	{
		ft_single_free(str1);
		ft_single_free(str2);
	}
	if (SD == 'D')
	{
		ft_double_free(str1);
		ft_double_free(str2);
	}
}
