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
	int					quote_closed;
	int					quote_counter;
	char				*temp;

	quote_closed = 1;
	temp = ft_strtrim(cmd, " ");
	saved = i;
	if (r)
		ft_reset_static_vars(&i, &saved);
	while (temp[i])
	{
		quote_counter = 0;
		if (temp[i] == '"')
		{
			ft_inc_uqh(temp, &i, &quote_closed);
			while (!quote_closed)
			{
				quote_counter++;
				ft_inc_uqh(temp, &i, &quote_closed);
			}
			return (ft_gc_strtrim(ft_gc_substr(temp,
						saved, (quote_counter + 1)), " "));
		}
		if ((ft_single_inset(temp[i], set) != -1) && quote_closed)
		{
			while ((ft_single_inset(temp[i], set) != -1) && temp[i])
				ft_inc_uqh(temp, &i, &quote_closed);
			return (ft_gc_strtrim(ft_gc_substr(temp,
						saved, ft_strlen_set(&temp[saved], set)), " "));
		}
		while ((ft_single_inset(temp[i], set) != -1) && temp[i])
			ft_inc_uqh(temp, &i, &quote_closed);
		ft_inc_uqh(temp, &i, &quote_closed);
	}
	while ((ft_single_inset(temp[i], set) != -1) && temp[i])
		ft_inc_uqh(temp, &i, &quote_closed);
	return (ft_gc_strtrim(ft_gc_substr(temp,
				saved, ft_strlen_set(&temp[saved], set)), " "));
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
