/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:42:00 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/22 13:43:22 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

// needs a fix :( will print null as first env for a unknown reason
void	ft_print_env(void)
{
	t_envlist	*temp;

	temp = ft_env_list(NULL);
	while (temp)
	{
		if (temp->var_name)
			printf("%s\n", temp->full_line);
		temp = temp->next;
	}
}

/*
** @TODO
*/
int	ft_env(void)
{
	ft_print_env();
	return (0);
}
