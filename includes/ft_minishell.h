#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "../libft/libft.h"
# include <curses.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include "../gc/ft_garbage_collector.h"

// IN
# define IN 2 // <
# define HERE_DOC 3 // << here doc

// OUT
# define STDOUT -1 // last command in chain
# define PIPE 0 // |
# define OUT 1 // >
# define APPEND 4 // >> append

// built_sys
# define BUILT_IN 5
# define SYS 6

/*
	Environment list
*/
typedef struct s_envlist
{
	char				**envp;
	char 				*full_line;
	char				*var_name;
	char				*value;
	struct s_envlist *next;
} 			t_envlist;

// todo: add length of linked list

typedef struct s_command
{
	char				*command;
	char				*original_string;
	char				*file; // the path to the file
	char				**args;
	int					in_flag;  // flag at the beginning
	int					out_flag; // flag at the end
	int					builtin_sys_flag; // determines if builtin or ssy command
	int					op; // ? later
	struct s_command	*next;
}			t_command;

//pipex
typedef struct s_pipes
{
	int					in;
	int					out;

	int					stout;

	int					pipe[2];
	int					temp_fd;
}			t_pipes;

typedef struct s_child
{
	int					i;
	char				*full_path;
	char				*temp;
	char				**cmnd;
	char				**paths;
}			t_child;


//trash?
//cat hello.txt | grep -e "test asdf asdf"

//first linked list
//command = cat
//args = (cat) (hello.txt)
//file = fd descriptor for hello.txt
//flag = 1
//next -> linked list two

//linked list two
// command = grep
// args = grep (-e) ("test asdf asdf")
// flag = 8
// next -> null

/*

	-> char **ft_split_no_quotes() TODO

	void ft_parser(cmd)
	{
		struct t_command *command_info;
		if (cmd)
		{

			char **command_parts = 	ft_split_no_quotes(cmd);
			char *command = command_parts[0];
			command_info->command = command_parts[0];
			command_info->original_string = cmd;
			command_info->arg = command_parts;
			add_to_command_history();
		}
	}

*/


int			main(int argc, char **argv, char **envp);
void		ft_handle_sig(int sig);

//parsing
char			***ft_split_machine(char *str, char dlmtr);
t_command		*ft_parser(char *cmd, int in_flag, int out_flag, char *file_name);
int				ft_command_size(t_command *lst);
char			**ft_split_quote(char *s, char c);
t_command		*ft_parse_in_commands(char *cmds);

//envlist
t_envlist	*ft_env_list(t_envlist *env_list);
t_envlist	*ft_create_env_list(char **envp);

//path_helpers
int			ft_check_command(char *exec);
char 		*ft_join_path(char *path, char *executable);
int			ft_check_file_exists(char *file);

//pipex
void		ft_pipex(t_pipes *p, t_command *commands, t_envlist *envp);
void    	ft_pipe(t_pipes *p);
void   		ft_open_infile(t_pipes *p, t_command *commands);
void    	ft_init_dup(t_pipes *p);
void		ft_open_outfile(t_pipes *p, t_command *commands);

void   		ft_system_command(t_pipes *p, t_command *commands, t_envlist *envp);
int			ft_execute(t_command *commands, t_envlist *envp);
void		ft_outfile_dup(t_pipes *p);
void		ft_pipe_pre_dup(t_pipes *p);
void		ft_pipe_after_dup(t_pipes *p);
void		ft_stdout_dup(t_pipes *p);

void		ft_close(t_pipes *p);
void		command_not_found(char *command);
int			ft_array_len(char **argv);
int			check_file(char *filename, char RW);

//????
char		*ft_find_executable_path(char *exec);
void		ft_arg_printer(char **args);

//buildins
int			ft_pwd(void);
int			ft_env(void);
int			ft_echo(char *cmd, int n);

//free_functions
void		ft_custom_free(char **str1, char **str2, char SD);
void		ft_single_free(char **string);
void		ft_double_free(char	**string);
void		ft_triple_free(char	***string);

// Command list handling
void		ft_commandaddback(t_command **lst, t_command *new);
t_command	*ft_newcommand(char *command);

#endif
