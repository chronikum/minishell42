#include "unistd.h"
#include <stdlib.h>

# ifndef FT_GARBAGE_COLLECTOR_H
# define FT_GARBAGE_COLLECTOR_H

typedef void*	t_pointer;

void		*ft_malloc(size_t sz);
void		ft_freeall(void);
void		*ft_free_pointer(void *pointer);
t_pointer	*ft_gclststart(t_pointer *pointer);
#endif