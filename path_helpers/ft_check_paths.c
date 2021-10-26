#include "../includes/ft_minishell.h"

/*
	Joins path and slash and executable name and returns string
*/
char *ft_join_path(char *path, char *executable)
{
	char *pathwithslash;
	char *pathwithslashandexecutable;

	pathwithslash = ft_strjoin(path, "/");
	pathwithslashandexecutable = ft_strjoin(pathwithslash, executable);
	
	free(pathwithslash);
	return (pathwithslashandexecutable);
}

/*
	Checks if a command exists in the given path variable
*/
int	ft_check_command(char *exec)
{
	char	**paths;
	int		i;
	char	*temp_path;

	i = 0;
	paths = ft_split(getenv("PATH"), ':');

	while (paths[i])
	{
		temp_path = ft_join_path(paths[i], exec);
		if (access(temp_path, F_OK) != -1)
		{
			free(temp_path);
			ft_double_free(paths);
			printf("FOUND COMMAND %s!\n", exec);
			return (1);
		}
		i++;
	}
	free(temp_path);
	ft_double_free(paths);
	printf("Command not found: %s", exec);
	return (-1);
}