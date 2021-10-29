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

# define PIPE 1 // |
# define OUT 2 // >
# define IN 3 // <
# define LEFT 4 // <<
# define RIGHT 5 // >>
# define BUILT 6
# define SYS 7
# define STDOUT 8 // last command in chain

/*
	Environment list
*/
typedef struct s_envlist
{
	char	**envp;
	char 	*full_line;
	char	*var_name;
	char	*value;
	struct s_envlist *next;
} t_envlist;

// todo: add length of linked list

typedef struct s_command
{
	char				*command;
	char				*original_string;
	char				*file;
	char				**args;
	int					flag;
	int					op;
	struct s_command	*next;
}	t_command;

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
//pipex
typedef struct s_pipes
{
	int		stin;
	int		stout;

	int		in;
	int		out;
	int		cmnd_count;
	int		argc_process;

	int		pipe[2];
	int		temp_fd;
}			t_pipes;

typedef struct s_child
{
	int		i;
	char	*full_path;
	char	*temp;
	char	**cmnd;
	char	**paths;
}			t_child;


int			main(int argc, char **argv, char **envp);
void		ft_handle_sig(int sig);

//parsing
char		***ft_split_machine(char *str, char dlmtr);
t_command	*ft_parser(char *cmd);
int			ft_command_size(t_command *lst);
char		**ft_split_quote(char *s, char c);

//envlist
t_envlist	*ft_env_list(t_envlist *env_list);
t_envlist	*ft_create_env_list(char **envp);

//path_helpers
int			ft_check_command(char *exec);
char 		*ft_join_path(char *path, char *executable);

//pipex
int			execution(int argc, t_command argv, t_envlist envp);
void		cutlery(t_pipes *p, t_command argv, t_envlist envp);
void		cutlery_close(t_pipes *p);
int			child(t_pipes *p, t_command argv, t_envlist envp);
//void		ft_open_out(t_pipes *p, /*PATH TO OUTFILE*/);
void		cutlery_dup(t_pipes *p);

void		command_not_found(t_command argv, char CP);
int			ft_array_len(char **argv);
char		**path_finder(char **envp);
int			check_file(char *filename, char RW);
char		*ft_find_executable_path(char *exec);
void		ft_arg_printer(char **args);

//buildins
int			ft_pwd(void);
int			ft_env(void);
int			ft_echo(char *cmd, int n);
t_command	*ft_parser(char *cmd);

//free_functions
void		ft_custom_free(char **str1, char **str2, char SD);
void		ft_single_free(char **string);
void		ft_double_free(char	**string);
void		ft_triple_free(char	***string);
#endif
