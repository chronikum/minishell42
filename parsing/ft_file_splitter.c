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
	t_fs_aux			*fx;

	fx = ft_new_split_aux(cmd);
	saved = i;
	if (r)
		ft_reset_static_vars(&i, &saved);
	while (fx->temp[i])
	{
		fx->quote_counter = 0;
		if (fx->temp[i] == '"')
		{
			ft_fs_skip_to_quote_end(fx, &i);
			return (ft_gc_strtrim(ft_gc_substr(fx->temp,
						saved, (fx->quote_counter + 1)), " "));
		}
		if ((ft_single_inset(fx->temp[i], set) != -1) && fx->quote_closed)
			return (ft_return_cq_filename(fx, &i, set, saved));
		ft_fs_skip_until_notinset(fx, &i, set);
		ft_inc_uqh(fx->temp, &i, &fx->quote_closed);
	}
	ft_fs_skip_until_notinset(fx, &i, set);
	return (ft_gc_strtrim(ft_gc_substr(fx->temp,
				saved, ft_strlen_set(&fx->temp[saved], set)), " "));
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
