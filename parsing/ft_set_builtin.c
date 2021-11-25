#include "../includes/ft_minishell.h"

/*
	Checks if the command is a builtin command
*/
static int	ft_check_builtin(char *command)
{
	if (ft_sb_strcmp(command, "pwd") == 0)
		return (1);
	else if (ft_spongebob_strncmp(command, "exit", ft_strlen("exit")) == 0)
		return (1);
	else if (ft_spongebob_strncmp(command, "env", ft_strlen("env")) == 0)
		return (1);
	else if (ft_spongebob_strncmp(command, "echo", ft_strlen("echo")) == 0)
		return (1);
	else if (ft_spongebob_strncmp(command, "cd", ft_strlen("cd")) == 0)
		return (1);
	else if (ft_spongebob_strncmp(command, "export", ft_strlen("export")) == 0)
		return (1);
	else if (ft_spongebob_strncmp(command, "unset", ft_strlen("unset")) == 0)
		return (1);
	return (0);
}

/*
	Sets the buildin sys flag to 5 or 6
*/
void	ft_set_builtin_flag(t_command *command)
{
	char	*main_command;

	if (ft_check_builtin(ft_gc_strtrim(command->args[0], " ")))
		command->builtin_sys_flag = BUILT_IN;
	else if (ft_find_executable_path(command->args[0]))
		command->builtin_sys_flag = SYS;
	else
		command->builtin_sys_flag = SYS;
	ft_set_flags(command);
}