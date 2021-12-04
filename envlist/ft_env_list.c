/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:28:06 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 17:28:07 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

t_envlist	*ft_env_list(t_envlist *env_list)
{
	static t_envlist	*list;

	if (env_list)
		list = env_list;
	return (list);
}
