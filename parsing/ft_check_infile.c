#include "../includes/ft_minishell.h"

static void	ft_add_infile(t_command *command, char *command_section)
{
	char		*file_name;
	
	file_name = ft_get_cmd_filename(command_section);
	command->files = ft_new_file(file_name, file_name, 1, 0);
	
}

/*
	Returns the infile command if the command has an infile
*/
t_command	*ft_check_infile(char *command_section)
{
	t_command	*command;
	int			i;
	
	i = 0;
	if (command_section[0] == '<' && command_section[1] != '<')
	{
		command = ft_newcommand(command_section);
		command->in_flag = 1;
		command->out_flag = 0;
		while (ft_strlen_set(&command_section[i], " ") == -1)
			i++;
		command->args = ft_splint(command_section);
		ft_add_infile(command, command_section);
		
		return (command);
	}
	else
		return (NULL);
}