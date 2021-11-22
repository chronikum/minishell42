/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:45:03 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/22 13:45:05 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Debugging helper for funkyoctopus
	// IN
	# define IN 2 // <
	# define HERE_DOC 3 // << here doc

	// OUT
	# define STDOUT -1 // last command in chain
	# define PIPE 0 å// |
	# define OUT 1 // >
	# define APPEND 4 // >> append

	// built_sys
	# define BUILT_IN 5
	# define SYS 6
	# define SKIP 8
*/
char	*ft_translate_flags(int flag)
{
	if (flag == -1)
		return ("STDOUT");
	if (flag == 0)
		return ("PIPE");
	if (flag == 1)
		return ("OUT");
	if (flag == 2)
		return ("IN");
	if (flag == 3)
		return ("HERE_DOC");
	if (flag == 4)
		return ("APPEND");
	if (flag == 5)
		return ("BUILT_IN");
	if (flag == 6)
		return ("SYS");
	if (flag == 8)
		return ("SKIP");
	return ("UNDEFINED");
}
