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

int			main(int argc, char **argv, char **envp);
void		ft_handle_sig(int sig);

char		***ft_split_machine(char *str, char dlmtr);

int			ft_pwd(void);
int			ft_env(void);
int			ft_echo(char *cmd, int n);

t_envlist	*ft_env_list(t_envlist *env_list);
t_envlist	*ft_create_env_list(char **envp);
#endif
