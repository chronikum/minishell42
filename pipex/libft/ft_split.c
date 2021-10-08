/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:28:15 by olgerret          #+#    #+#             */
/*   Updated: 2021/06/29 15:29:41 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len_counter(char const *s, char c, int *pword_start)
{
	int	i;
	int	j;
	int	word_len;

	i = *pword_start;
	while (s[i] == c)
		i++;
	j = *pword_start;
	while (s[i] != c && s[i] != '\0')
		i++;
	word_len = (i - j);
	return (word_len);
}

static int	word_counter(char const *s, char c, int *pword_start)
{
	int	i;
	int	words;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	*pword_start = i;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c)
			{
				i++;
				if (s[i] == '\0')
					return (words);
			}
		}
		i++;
	}
	return (words);
}

static char	*string_printer(char const *s, char c, int *pword_start)
{
	int		i;
	int		word_len;
	char	*str;

	word_len = word_len_counter(s, c, pword_start);
	str = (char *)malloc((word_len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	i = 0;
	while (i < word_len && s[*pword_start] != c)
	{
		str[i] = s[*pword_start];
		i++;
		*pword_start += 1;
	}
	while (s[*pword_start] == c)
		*pword_start += 1;
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		word_start;
	int		words;
	int		i;
	char	**result;
	char	*string;

	if (s == 0)
		return (0);
	word_start = 0;
	words = word_counter(s, c, &word_start);
	i = 0;
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (result == 0)
		return (0);
	while (i < words)
	{
		string = string_printer(s, c, &word_start);
		if (string == 0)
			return (0);
		result[i++] = string;
	}
	result[i] = 0;
	return (result);
}
