/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:31:06 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/08 10:04:20 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_minishell.h"

int	g_global;

/*
**	Quits the program
*/
void	ft_quit_signal(int signal)
{
	(void) signal;
	if (g_global == 2)
	{
		g_global = 1;
	}
}

/*
**	Quits the program
*/
void	ft_quit(void)
{
	ft_freeall();
	exit(0);
}

/*
**	Signal handler SIGINT
**	Handles incoming SIGINT signal by making a new line
**	and replacing current input on the new line with empty string.
**	Also, redisplays when done :)
*/
void	sig_handler_int(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_global = 1;
	}
}

/**
 * Gets the command list for the give char array
 */
void	ft_execute_terminal_command(char *command)
{
	t_command	*list;
	t_pipes		*p;
	t_envlist	*envp;

	p = malloc(sizeof(t_pipes));
	command = ft_insert_exit_code(command);
	command = ft_translate_envs(command);
	command = ft_gc_strtrim(command, " |>");
	if (ft_strlen(ft_gc_strtrim(command, " \"<>")) == 0)
		return ;
	list = ft_parse_in_commands(command);
	envp = ft_env_list(NULL);
	p->temp_fd = dup(STDIN_FILENO);
	p->stout = dup(1);
	while (list != NULL)
	{
		ft_pipex(p, list, envp);
		list = list->next;
	}
	free(p);
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	int		oldstdin;
	int		oldstdout;

	oldstdin = dup(0);
	oldstdout = dup(1);
	cmd = NULL;
	ft_init_shell(envp);
	while (1 && argc && argv && envp)
	{
		dup2(oldstdin, 0);
		dup2(oldstdout, 1);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &sig_handler_int);
		cmd = readline(ft_get_nice_prompt());
		if (cmd == NULL)
			ft_quit();
		if (ft_strncmp(cmd, "", ft_strlen(cmd)))
		{
			ft_execute_terminal_command(cmd);
			add_history(cmd);
		}
	}
	return (0);
}
