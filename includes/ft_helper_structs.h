#ifndef FT_HELPER_STRUCTS_H
# define FT_HELPER_STRUCTS_H

typedef struct s_envit
{
	unsigned int	i;
	int				qclosed;
	char			*var_name;
	char			*result;
	int				total;
}			t_envit;

typedef struct s_strnstr {
	unsigned int	i;
	unsigned int	j;
	unsigned int	needle_len;
	char			*phaystack;
	int				quote_closed;
}	t_strnstr;

#endif