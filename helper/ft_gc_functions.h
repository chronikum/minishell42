/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:29:42 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/05 12:20:21 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GC_FUNCTIONS_H
# define FT_GC_FUNCTIONS_H

# include "../gc/ft_garbage_collector.h"
# include "../libft/libft.h"

char	*ft_gc_strdup(const char *s1);
char	*ft_strtouppercase(char *str);
char	*ft_strtolowercase(char *str);
char	*ft_gc_substr(char const *s, unsigned int start, int len);
char	*ft_gc_strtrim(char const *s1, char const *set);
int		ft_sb_strcmp(char *s1, char *s2);
int		ft_strcmp_len(char *s1, char *s2);
char	*ft_gc_itoa(int n);

#endif