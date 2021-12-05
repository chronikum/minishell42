#include "../includes/ft_minishell.h"

t_fs_aux	*ft_new_split_aux(char *cmd)
{
	t_fs_aux	*fs_aux;

	fs_aux = ft_malloc(sizeof(t_fs_aux));
	fs_aux->quote_closed = 1;
	fs_aux->quote_counter = 0;
	fs_aux->temp = ft_strtrim(cmd, " ");
	return (fs_aux);
}

char	*ft_return_cq_filename(t_fs_aux *fx, unsigned int *i,
		char *set, unsigned int saved)
{
	ft_fs_skip_until_notinset(fx, i, set);
	return (ft_gc_strtrim(ft_gc_substr(fx->temp,
				saved, ft_strlen_set(&fx->temp[saved], set)), " "));
}
