#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "../libft/libft.h"
# include <curses.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

typedef struct s_envlist 
{
	char 	*full_line;
	char	*var_name;
	char	*value;	
	struct s_envlist *next; 
} t_envlist;


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

char		***ft_split_machine(char *str, char dlmtr);

int			ft_pwd(void);
int			ft_env(void);
int			ft_echo(char *cmd, int n);

t_envlist	*ft_env_list(t_envlist *env_list);
t_envlist	*ft_create_env_list(char **envp);

int			ft_check_command(char *exec);

void		ft_double_free(char	**string);
void		ft_single_free(char **string);
#endif
