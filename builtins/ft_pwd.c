/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:42:02 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/22 13:42:03 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

int	ft_pwd(void)
{
	char	*str;

	str = malloc(sizeof(char) * 4096);
	str = getcwd(str, 4096);
	if (!str)
		return (1);
	printf("%s\n", str);
	free(str);
	return (0);
}
