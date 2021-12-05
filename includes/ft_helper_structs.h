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

typedef struct s_gnw_splint {
	int		q[3];
	char	*temp;
}	t_gnw_splint;

typedef struct s_exit_code_aux {
	unsigned int	i;
	int				quote_closed;
	char			*var_name;
	char			*result;
	int				total;
}	t_exit_code_aux;

t_strnstr	*ft_get_strnstr(char *needle, char *haystack);

#endif