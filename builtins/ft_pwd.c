/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:42:02 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/08 09:21:20 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

int	ft_pwd(void)
{
	char	*str;

	str = ft_malloc(sizeof(char) * 4096);
	str = getcwd(str, 4096);
	if (!str)
		return (1);
	printf("%s\n", str);
	return (0);
}
