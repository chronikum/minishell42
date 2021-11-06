#include "ft_garbage_collector.h"

/*
	Frees the first pointer and sets the beginning at the end of
	the freed pointer
*/
static void	ft_free_first_pointer(t_pointer *allocated)
{
	t_pointer	old_start_pointer;

	old_start_pointer = *allocated;
	(*allocated) = (*((t_pointer *) old_start_pointer));
	free(old_start_pointer);
}

/*
	Frees the target pointer at (t_pointer) void *pointer.
*/
void	ft_free(t_pointer target)
{
	t_pointer	*start;
	t_pointer	addrs_cumulated;
	t_pointer	tmp;

	if (!target)
		return ;
	start = ft_gclststart(NULL);
	addrs_cumulated = start[0];
	while (addrs_cumulated && ((addrs_cumulated + sizeof(t_pointer)) != target))
	{
		tmp = addrs_cumulated;
		addrs_cumulated = (*(t_pointer *) addrs_cumulated);
	}
	if (addrs_cumulated == (*start))
		ft_free_first_pointer(start);
	else if (addrs_cumulated)
	{
		(*((t_pointer *)tmp)) = *((t_pointer *)addrs_cumulated);
		free(addrs_cumulated);
	}
}
