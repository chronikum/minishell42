/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:21 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:22 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"

t_strnstr	*ft_get_strnstr(char *needle, char *haystack)
{
	t_strnstr	*strnstrn;

	strnstrn = malloc(sizeof(t_strnstr));
	strnstrn->i = 0;
	strnstrn->j = 0;
	strnstrn->needle_len = ft_strlen(needle);
	strnstrn->phaystack = (char *)haystack;
	strnstrn->quote_closed = 1;
	return (strnstrn);
}

char	*ft_strnstr_quotes(const char *haystack, const char *needle, size_t len)
{
	t_strnstr	*st;

	st = ft_get_strnstr((char *) needle, (char *) haystack);
	if (needle[0] == '\0')
		return (st->phaystack);
	while (haystack[st->i] != '\0' && st->i < len)
	{
		while (haystack[st->i + st->j] == needle[st->j] && needle[st->j]
			!= '\0' && (st->i + st->j) < len && st->quote_closed)
		{
			ft_inc_uqh((char *) &haystack[st->i], &st->j, &st->quote_closed);
			if (st->j == st->needle_len)
				return (&st->phaystack[st->i]);
		}
		ft_inc_uqh((char *) haystack, &st->i, &st->quote_closed);
		st->j = 0;
	}
	return (NULL);
}

/*
	Searches a string not being surround by single quotes
*/
char	*ft_strnstr_single_quotes(
		const char *haystack, const char *needle, size_t len)
{
	t_strnstr	*st;

	st = ft_get_strnstr((char *) needle, (char *) haystack);
	if (needle[0] == '\0')
		return (st->phaystack);
	while (haystack[st->i] != '\0' && st->i < len)
	{
		while (haystack[st->i + st->j] == needle[st->j] && needle[st->j]
			!= '\0' && (st->i + st->j) < len && st->quote_closed)
		{
			ft_incs_uihand((char *) &haystack[st->i],
				&st->j, &st->quote_closed);
			if (st->j == st->needle_len)
				return (&st->phaystack[st->i]);
		}
		ft_incs_uihand((char *) haystack, &st->i, &st->quote_closed);
		st->j = 0;
	}
	return (NULL);
}

/*
	Makes sure the needle is neither being enclosed by double or single quotes.
	Ultimate quote handling function
*/
char	*ft_strnstr_nowhere_quotes(
		const char *haystack, const char *needle, size_t len)
{
	t_strnstr	*st;

	st = ft_get_strnstr((char *) needle, (char *) haystack);
	if (needle[0] == '\0')
		return (st->phaystack);
	while (haystack[st->i] != '\0' && st->i < len)
	{
		while (haystack[st->i + st->j] == needle[st->j] && needle[st->j]
			!= '\0' && (st->i + st->j) < len && st->quote_closed)
		{
			ft_usdq_handler((char *) &haystack[st->i], &st->j,
				&st->quote_closed, &st->quote_closed);
			if (st->j == st->needle_len)
				return (&st->phaystack[st->i]);
		}
		ft_usdq_handler((char *) haystack,
			&st->i, &st->quote_closed, &st->quote_closed);
		st->j = 0;
	}
	return (NULL);
}
