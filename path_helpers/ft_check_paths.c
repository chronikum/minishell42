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
	Gets the executable path
*/
char *ft_find_executable_path(char *exec) // as soon as exec is being accessed the program will stop.
{
	char	**paths;
	int		i;
	char	*temp_path;

	i = 0;
	paths = ft_split(getenv("PATH"), ':');
	printf("GOING IN!!\n");
	ft_arg_printer(paths);
	printf("FINISHED PRINTING PATHS\n");
	while (paths[i])
	{
		printf("ABOVE! \n");
		printf("LENGTH: %lu \n", ft_strlen(exec));
		printf("TRYING TO JOIN %s with PATH %s \n", exec, paths[i]); // as soon as you try to printf exec it will just not show up
		ft_putstr_fd("SECOND TEST! \n", 1);
		temp_path = ft_join_path(paths[i], exec);
		printf("JOINED PATH: %s \n", temp_path);
		if (access(temp_path, F_OK) != -1)
		{
			ft_double_free(paths);
			paths = NULL;
			printf("RETURNING HERE\n");
			return (temp_path);
		}
		i++;
	}
	printf("MOVING ON!\n");
	return (NULL);
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
			return (1);
		}
		i++;
	}
	free(temp_path);
	ft_double_free(paths);
	printf("urgent: command not found: %s\n", exec);
	return (-1);
}