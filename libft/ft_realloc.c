#include "libft.h"

void	*ft_realloc(void **src, size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (!dst)
	{
		free((*src));
		return (NULL);
	}
	if (!(*src))
	{
		free(dst);
		return (NULL);
	}
	ft_memmove(dst, (*src), size);
	free((*src));
	(*src) = NULL;
	return (dst);
}