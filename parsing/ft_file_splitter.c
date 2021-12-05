#include "../includes/ft_minishell.h"

static void	ft_reset_static_vars(unsigned int *i, unsigned int *saved)
{
	(*saved) = 0;
	(*i) = 0;
}

static char	*ft_get_next_word(char *cmd, int r, char *set)
{
	static unsigned int	saved = 0;
	static unsigned int	i = 0;
	t_fs_aux	*fs_aux;
	
	fs_aux = ft_new_split_aux(cmd);
	fs_aux->quote_closed = 1;
	fs_aux->temp = ft_strtrim(cmd, " ");
	saved = i;
	if (r)
		ft_reset_static_vars(&i, &saved);
	while (fs_aux->temp[i])
	{
		fs_aux->quote_counter = 0;
		if (fs_aux->temp[i] == '"')
		{
			ft_inc_uqh(fs_aux->temp, &i, &fs_aux->quote_closed);
			while (!fs_aux->quote_closed)
			{
				fs_aux->quote_counter++;
				ft_inc_uqh(fs_aux->temp, &i, &fs_aux->quote_closed);
			}
			return (ft_gc_strtrim(ft_gc_substr(fs_aux->temp,
						saved, (fs_aux->quote_counter + 1)), " "));
		}
		if ((ft_single_inset(fs_aux->temp[i], set) != -1) && fs_aux->quote_closed)
		{
			while ((ft_single_inset(fs_aux->temp[i], set) != -1) && fs_aux->temp[i])
				ft_inc_uqh(fs_aux->temp, &i, &fs_aux->quote_closed);
			return (ft_gc_strtrim(ft_gc_substr(fs_aux->temp,
						saved, ft_strlen_set(&fs_aux->temp[saved], set)), " "));
		}
		while ((ft_single_inset(fs_aux->temp[i], set) != -1) && fs_aux->temp[i])
			ft_inc_uqh(fs_aux->temp, &i, &fs_aux->quote_closed);
		ft_inc_uqh(fs_aux->temp, &i, &fs_aux->quote_closed);
	}
	while ((ft_single_inset(fs_aux->temp[i], set) != -1) && fs_aux->temp[i])
		ft_inc_uqh(fs_aux->temp, &i, &fs_aux->quote_closed);
	return (ft_gc_strtrim(ft_gc_substr(fs_aux->temp,
				saved, ft_strlen_set(&fs_aux->temp[saved], set)), " "));
}

char	**ft_file_splitter(char *s, char *splitter)
{
	char	**result;
	char	*current;
	int		i;
	int		wc;

	i = 0;
	current = NULL;
	wc = ft_detect_mredirections(s);
	result = ft_malloc(sizeof(char *) * (wc + 1));
	while (current || i == 0)
	{
		if (!current)
			current = ft_gc_strtrim(ft_get_next_word(s, 1, splitter), "\"");
		if (!current)
			return (NULL);
		if (ft_strlen(current) != 0)
		{
			result[i] = current;
			i++;
		}
		if (current)
			current = ft_gc_strtrim(ft_get_next_word(s, 0, splitter), "\"");
	}
	result[i] = NULL;
	return (result);
}
