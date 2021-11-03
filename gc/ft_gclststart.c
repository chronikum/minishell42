#include "ft_garbage_collector.h"

/*
	Static, accessible variable where we map all our
	allocated memory in. This allows us to just append
	the stuff we need to it and easily manage freeing
	specific pointers.
*/
t_pointer	*ft_gclststart(t_pointer *pointer)
{
	static t_pointer	start = NULL;
	if (pointer)
		start = pointer;
	return (&start);
}