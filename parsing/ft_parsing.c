#include "../includes/ft_minishell.h"

int	ft_check_is_flag(char *p_flag)
{
	if (p_flag[0] == '-')
		return (1);
	if (p_flag[0] == '-' && p_flag[1] == '-')
		return (1);
	return (0);
}

t_command	*ft_parser(char *cmd)
{
	char **command_parts;
	char *main_command;
	t_command *command_struct;

	command_struct = malloc(sizeof(t_command));
	command_parts = ft_split(cmd, ' '); // Todo only split if not surrounded by quotes
	main_command = command_parts[0];
	if (ft_check_command(main_command) == 1) // check if command even exists
	{
		command_struct->command = main_command;
		command_struct->args = command_parts;
		printf("%s\n", ft_find_executable_path(main_command));
		pid_t pid = fork();
		if (pid == -1)
			exit (0);
		if (pid == 0)
			execution(1, (*command_struct), (*ft_env_list(NULL)));
	}


	return (command_struct);
}