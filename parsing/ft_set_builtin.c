#include "../includes/ft_minishell.h"

/*
	Checks if the command is a builtin command
*/
static int	ft_check_builtin(char *command)
{
	if (ft_sb_strcmp(command, "pwd") == 0)
		return (1);
	else if (ft_sb_strcmp(command, "exit") == 0)
		return (1);
	else if (ft_sb_strcmp(command, "env") == 0)
		return (1);
	else if (ft_sb_strcmp(command, "echo") == 0)
		return (1);
	else if (ft_sb_strcmp(command, "cd") == 0)
		return (1);
	else if (ft_sb_strcmp(command, "export") == 0)
		return (1);
	else if (ft_sb_strcmp(command, "unset") == 0)
		return (1);
	return (0);
}

/*
	Sets the buildin sys flag to 5 or 6
*/
void	ft_set_builtin_flag(t_command *command)
{
	if (command->in_flag == 1)
		return;
	if (ft_check_builtin(ft_gc_strtrim(command->args[0], " ")))
		command->builtin_sys_flag = BUILT_IN;
	else if (ft_find_executable_path(command->args[0]))
		command->builtin_sys_flag = SYS;
	else
		command->builtin_sys_flag = SYS;
}