/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_magic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:28:16 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 17:28:17 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	We can get or set the most recent exit code here
*/
int	ft_set_most_recent_exit_code(int exit_code, int set)
{
	static int	exit_code_saved = 0;

	if (set == 1)
	{
		exit_code_saved = exit_code;
		return (1);
	}
	return (exit_code_saved);
}
