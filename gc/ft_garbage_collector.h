/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:02:03 by olgerret          #+#    #+#             */
/*   Updated: 2021/11/22 14:02:04 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GARBAGE_COLLECTOR_H
# define FT_GARBAGE_COLLECTOR_H

# include "unistd.h"
# include <stdlib.h>
# include "../includes/ft_minishell.h"

typedef void*	t_pointer;

void		*ft_malloc(size_t sz);
void		ft_freeall(void);
void		*ft_free_pointer(void *pointer);
t_pointer	*ft_gclststart(t_pointer *pointer);
void		*ft_gc_memdup(const void *mem, size_t size);
#endif
