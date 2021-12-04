/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nice_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:30:48 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/04 17:30:49 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/*
	Returns a nice styled prompt with the username and host
	machine
*/
char	*ft_get_nice_prompt(void)
{
	char	*user;
	char	*command_prompt;
	char	*colored_part;
	char	*username;
	char	*user_at_char;

	username = "";
	user_at_char = ft_gc_strjoin(ft_gc_strjoin(YELLOW_COLOR, "⇎"), RESET_COLOR);
	if (ft_find_envlist("USER"))
		username = ft_find_envlist("USER")->value;
	user = ft_gc_strjoin(ft_gc_strjoin(RED_COLOR, username), RESET_COLOR);
	colored_part = "minishell\033[0m \033[0;36m⇉\033[0m ";
	command_prompt = ft_gc_strjoin(ft_gc_strjoin(user,
				user_at_char), colored_part);
	return (command_prompt);
}
