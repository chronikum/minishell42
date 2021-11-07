#ifndef FT_GC_FUNCTIONS_H
# define FT_GC_FUNCTIONS_H

# include "../gc/ft_garbage_collector.h"
# include "../libft/libft.h"

char	*ft_gc_strdup(const char *s1);
char	*ft_strtouppercase(char *str);
char	*ft_strtolowercase(char *str);
char	*ft_gc_substr(char const *s, unsigned int start, int len);
char	*ft_gc_strtrim(char const *s1, char const *set);

#endif