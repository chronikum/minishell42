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