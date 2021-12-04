/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_shellname.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:30:54 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 17:30:55 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Sets the shell name in the SHELL env variable
	(likes bash does!)
*/
void	set_shell_envvariable(void)
{
	ft_setenv("SHELL", "minishell");
}
