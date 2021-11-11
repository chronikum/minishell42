#include "../includes/ft_minishell.h"


///*
//	Creates a new file list with given values
//	char *filename
//	char *full_filename
//	int in
//	int out
//*/
//t_files	*ft_new_file(char *filename, char *path, int in, int out)
//{
//	t_files	*new;

//	new = ft_malloc(sizeof(t_files));
//	new->file_name = filename;
//	new->path = path;
//	new->in = in;
//	new->out = out;
//	return (new);
//}

/*
	Creates a file list depening on the command char array input
*/
char	**ft_create_file_list(char *command)
{
	char **result;

	result = ft_multi_splint(command, "<>");

	return result;
}