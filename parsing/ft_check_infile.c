#include "../includes/ft_minishell.h"

static void	ft_add_infile(t_command *command, char *command_section)
{
<<<<<<< HEAD
	char *file_name;
	
	file_name = ft_get_cmd_filename(command, command_section);
	command->in_flag = IN;
	command->out_flag = IN;
	command->files = ft_new_file(file_name, file_name, 0, 0);
	printf("FINDING FILE NAME: %s\n", file_name);
=======
	char		*file_name;

	file_name = ft_get_cmd_filename(command_section);
	command->files = ft_new_file(file_name, file_name, 1, 0);
>>>>>>> 199376a4458a372f2640f1d12c6cd63ce7e9539e
}

/*
	Returns the infile command if the command has an infile
*/
t_command	*ft_check_infile(t_command *command, char *command_section)
{
<<<<<<< HEAD
=======
	t_command	*command;
	int			i;

	i = 0;
>>>>>>> 199376a4458a372f2640f1d12c6cd63ce7e9539e
	if (command_section[0] == '<' && command_section[1] != '<')
	{
		command->in_flag = IN;
		command->out_flag = 0;
		ft_add_infile(command, command_section);
<<<<<<< HEAD
		ft_set_builtin_flag(command);
=======
>>>>>>> 199376a4458a372f2640f1d12c6cd63ce7e9539e
		return (command);
	}
	else
		return (NULL);
}
