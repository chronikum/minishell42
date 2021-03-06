/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:02:05 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/08 10:16:36 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_garbage_collector.h"

/*
	If malloc fails, we need to handle that accordingly. So let us
	just exit with 1 after cleaning up memory!
*/
static void	*ft_no_memory(void)
{
	ft_freeall();
	printf("Error: Out of memory. We protected our mallocs!");
	exit(1);
	return (NULL);
}

/*
	Appends a new pointer
*/
static void	ft_append_to_pointer_mem(t_pointer new_p)
{
	t_pointer	*start;

	start = ft_gclststart(NULL);
	(*((t_pointer *)new_p)) = (*start);
	(*start) = new_p;
}

/*
	Mallocates a new pointer with the size size
	Returns a void pointer

	Adds the new pointer at the beginning of the
	static allocated pointer list which can be found
	in ft_gclststart
*/
void	*ft_malloc(size_t size)
{
	t_pointer	new_p;

	if (size == 0)
		return (NULL);
	new_p = malloc(sizeof(t_pointer) + size);
	if (!new_p)
		return (ft_no_memory());
	ft_append_to_pointer_mem(new_p);
	return (new_p + sizeof(t_pointer));
}
