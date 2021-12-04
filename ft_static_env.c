/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:31:08 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 17:31:09 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_minishell.h"

char	**ft_enver(char **enver)
{
	static char	**env = NULL;

	if (enver)
		env = enver;
	return (env);
}
