/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:41:55 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/22 13:42:29 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

/**
 * Will "echo" the string out but will
 * remove quotes without esacping sequence (\)
 */
int	ft_echo_string(char **string, int n)
{
	int	i;
	int	s;

	i = 0;
	s = n;
	if (n == 0)
		s = 2;
	while (string[s])
	{
		i = 0;
		while (string[s][i])
		{
			if (string[s][i] != '"' && string[s][i] != '\'')
				ft_putchar_fd(string[s][i], 1);
			else if (string[s][i] == '"' &&
				string[s][i - 1] == '\\' && string[s][i] != '\'')
				ft_putchar_fd(string[s][i], 1);
			i++;
		}
		s++;
		ft_putchar_fd(' ', 1);
	}
	if (n)
		ft_putchar_fd('\n', 1);
	return (0);
}

/**
 * Counts how many unescaped quotes are in a character sequence
 */
int	ft_count_quotes(char *characters)
{
	int	counter;
	int	counted_characters;

	counter = 0;
	counted_characters = 0;
	if (!characters)
		return (0);
	while (characters[counter])
	{
		if (characters[counter] == '"' && characters[counter - 1] != '\\')
			counted_characters++;
		counter++;
	}
	return (counted_characters);
}

/**
 * Returns one if was successful.
 * Checks for escaping quotes and quotes at and or beginning or
 * no quotes at all
 * TODO: Check forbidden signs like double exclamation mark
 * TODO: Clean the text_to_echo up so no unescaped quotes remain in output
 *
 */
int	ft_check_quotes(char *text_to_echo)
{
	if (ft_count_quotes(text_to_echo) % 2 == 0)
		return (1);
	return (0);
}

/*
	Returns one if paramater is a flag
*/
int	ft_has_n_flag(char *param)
{
	if (!param)
		return (0);
	if (ft_strlen(param) >= 2)
	{
		if (ft_gc_strtrim(param, " ")[0] == '-')
			return (ft_gc_strtrim(param, " ")[1] == 'n');
	}
	return (0);
}

/**
 * Returns zero on success
 * Returns one if something fails
 * Takes t_command
 */
int	ft_echo(t_command *command)
{
	char	*cmd;
	int		n;
	char	*string_to_echo;

	cmd = command->args[0];
	n = ft_has_n_flag(command->args[1]);
	if (n)
	{
		if (command->args[2])
			string_to_echo = command->args[2];
		else
			string_to_echo = "";
	}
	else
		string_to_echo = command->args[1];
	if (ft_check_quotes(string_to_echo) && !n)
		return (ft_echo_string(command->args, 1));
	else if (ft_check_quotes(string_to_echo) && n)
		return (ft_echo_string(command->args, 0));
	else
		ft_putstr_fd("Error\n", 2);
	return (1);
}
