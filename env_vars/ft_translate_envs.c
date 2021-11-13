#include "../includes/ft_minishell.h"


/*
	Gets called when a quote is being seen. Toggles a int (pointer)
*/
static void	ft_toggle_quote(int *quote_toggle)
{
	if ((*quote_toggle))
		(*quote_toggle) = 0;
	else
		(*quote_toggle) = 1;
}

/*
	Increases counter by one and toggles quote counter if it encounters one
*/
static void	ft_increase_i_quote_handler(char *cmd, unsigned int *i, int *quote)
{
	if (cmd[(*i)] == '\'')
		ft_toggle_quote(quote);
	(*i)++;
}


/*
	Gets env value or an empty string
*/
static	char	*ft_get_value_from_env(char *key)
{
	t_envlist	*env;
	
	env = ft_find_envlist(ft_gc_strtrim(key, "$\""));
	if (env)
		return env->value;
	return "";
}

static	int	ft_total_count(char *command)
{
	unsigned int	i;
	int				quote_closed;
	char			*var_name;
	int				total;

	i = 0;
	quote_closed = 1;
	total = 0;
	while (command[i])
	{
		if (command[i] == '$' && quote_closed)
		{
			var_name = ft_substr(command, i, ft_strlen_set(&command[i], " |><"));
			i+=ft_strlen_set(&command[i], " |><");
			total+=(int) ft_strlen(ft_get_value_from_env(var_name));
		}
		ft_increase_i_quote_handler(command, &i, &quote_closed);
		total++;
	}
	
	return (total);
}

char	*ft_translate_envs(char *command)
{
	unsigned int	i;
	int				quote_closed;
	char			*var_name;
	char			*result;
	int				offset;
	int				inner_i;
	int				total;

	result = malloc(sizeof(char) * ft_total_count(command) + 1);
	i = 0;
	offset = 0;
	total = 0;
	quote_closed = 1;
	printf("COUNTING: %d\n", ft_total_count(command));
	while (command[i])
	{
		printf("NOW LOOKING AT CHAR: %c\n", command[i]);
		if (command[i] == '$' && quote_closed)
		{
			inner_i = 0;
			var_name = ft_get_value_from_env(ft_substr(command, i, ft_strlen_set(&command[i], " |><")));
			i+=ft_strlen_set(&command[i], " |><");
			while (var_name[inner_i])
			{
				result[total] = var_name[inner_i];
				inner_i++;
				total++;
			}
		}
		else
		{
			result[total] = command[i];
		}
		total++;
		ft_increase_i_quote_handler(command, &i, &quote_closed);
	}
	result[total] = '\0';
	return (result);
}