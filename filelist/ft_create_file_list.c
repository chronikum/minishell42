#include "../includes/ft_minishell.h"


/*
	Creates a new file list with given values
	char *filename
	char *full_filename
	int in
	int out
*/
t_files	*ft_new_file(char *filename, char *path, int in, int out)
{
	t_files	*new;

	new = ft_malloc(sizeof(t_files));
	new->file_name = filename;
	new->path = path;
	new->in = in;
	new->out = out;
	new->next = NULL;
	return (new);
}

/*
	Creates a file list depening on the command char array input
*/
t_files	*ft_create_file_list(char *command)
{
	char	**result;
	int		i;
	t_files	*files;
	t_files	*start;

	//substring = ft_substr(command, 0, ft_strlenc(command, '|'));
	i = 0;
	result = ft_multi_splint(command, "<>");
	files = malloc(sizeof(t_list));
	start = NULL;
	files = NULL;
	while (ft_detect_mredirections(command) > i)
	{
		if (files)
		{
			files->is_multiple = 1;
			files->next = ft_new_file(result[i], result[i], 0, 0);
			files = files->next;
		}
		else
		{
			files->is_multiple = 0;
			files = ft_new_file(result[i], result[i], 0, 0);
			start = files;
		}
		i++;
	}

	return (start);
}