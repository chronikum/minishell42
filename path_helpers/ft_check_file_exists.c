#include "../includes/ft_minishell.h"

/*
	Returns one if at the absolute path or the relative path there is a file
	matching the given file name
*/
int	ft_check_file_exists(char *file)
{
	char	*temp_path;
	char	*local_path;

	local_path = "";
	if (!ft_strncmp("./", file, 2))
	{
		local_path = malloc(sizeof(char) * 4096);
		local_path = getcwd(local_path, 4096);
	}
	temp_path = ft_join_path(local_path, file);
	if (access(temp_path, F_OK) != -1)
		return (1);
	return (0);
}
