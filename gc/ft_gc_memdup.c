#include "ft_garbage_collector.h"

void	*ft_gc_memdup(const void *mem, size_t size)
{
	void	*dst;

	if (!mem)
		return (NULL);
	dst = ft_malloc(size);
	if (dst != NULL)
		ft_memcpy(dst, mem, size);
	return (dst);
}
