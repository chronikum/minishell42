/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:30:15 by olgerret          #+#    #+#             */
/*   Updated: 2021/12/08 09:38:48 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "../prompt/ft_prompt.h"
# include "../helper/ft_gc_functions.h"
# include "../debug_help/ft_debugging_help.h"
# include "../includes/ft_global.h"
# include "ft_helper_structs.h"

# define IN 2
# define HERE_DOC 3
# define STDOUT -1
# define PIPE 0
# define OUT 1
# define APPEND 4
# define BUILT_IN 5
# define SYS 6
# define SKIP 8

/*
	Environment list
*/
typedef struct s_envlist
{
	char				**envp;
	char				*full_line;
	char				*var_name;
	char				*value;
	struct s_envlist	*next;
}			t_envlist;

typedef struct s_files
{
	char				*file_name;
	int					is_multiple;
	char				*path;
	int					in;
	int					out;
	int					is_last;
	struct s_files		*next;
}			t_files;

typedef struct s_command
{
	char				*command;
	char				*original_string;
	char				*file;
	char				*delimiter;
	char				**args;
	int					in_flag;
	int					out_flag;
	t_files				*files;
	int					builtin_sys_flag;
	int					op;
	struct s_command	*next;
}			t_command;

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
	char				**paths;
}			t_child;

int			main(int argc, char **argv, char **envp);
void		ft_handle_sig(int sig);
void		ft_quit(void);
void		ft_init_shell(char **envp);
void		ft_execute_terminal_command(char *command);

char		***ft_split_machine(char *str, char dlmtr);
int			ft_command_size(t_command *lst);
char		**ft_splint(char *s);
t_command	*ft_parse_in_commands(char *cmds);
int			ft_strlenc(char *cmd, char c);
int			ft_strlen_set(char *cmd, char *set);
char		*ft_get_cmd_filename(t_command *command, char *cmd);
int			ft_spongebob_strncmp(char *s1, char *s2, int n);

t_envlist	*ft_env_list(t_envlist *env_list);
t_envlist	*ft_create_env_list(char **envp);

int			ft_check_command(char *exec);
char		*ft_join_path(char *path, char *executable);
int			ft_check_file_exists(char *file);

void		ft_pipex(t_pipes *p, t_command *commands, t_envlist *envp);
void		ft_io(t_pipes *p, t_command *commands);
void		ft_out_or_append(t_pipes *p, t_command *commands);
char		*ft_command_from_path(char *args_zero);
void		ft_multi_redirections(t_pipes *p, t_command *commands);

void		ft_mr_while_loop(t_pipes *p, t_command *commands, t_files	*temp);
int			ft_mr_open_last(t_pipes *p, t_command *commands, t_files *temp);
void		ft_here_doc(t_pipes *p, t_command *commands);
void		sig_handler_int2(int signal);
int			ft_run_builtin(t_command *commands);

void		ft_pipe(t_pipes *p);
void		ft_open_infile(t_pipes *p, t_command *commands);
void		ft_open_outfile(t_pipes *p, t_command *commands);
void		ft_open_error(t_pipes *p, t_command *commands);
void		ft_init_dup(t_pipes *p);

void		ft_system_command(t_pipes *p, t_command *commands, t_envlist *envp);
void		ft_execute(t_command *commands, t_envlist *envp);
void		ft_stdout_dup(t_pipes *p);
void		ft_outfile_dup(t_pipes *p);
void		ft_pipe_pre_dup(t_pipes *p);

void		ft_pipe_after_dup(t_pipes *p);
void		ft_close(t_pipes *p, t_command *commands);
void		ft_command_not_found(char *command);
int			ft_array_len(char **argv);
int			ft_check_file(char *filename);

char		*ft_find_executable_path(char *exec);
void		ft_arg_printer(char **args);
int			ft_detect_mredirections(char *command);
char		**ft_file_splitter(char *s, char *splitter);
void		ft_set_builtin_flag(t_command *command);
void		ft_set_flags(t_command *command);
void		ft_add_files(t_command *command);
void		ft_set_heredoc(t_command *command, char *string);
char		*ft_strnstr_quotes(const char *haystack,
				const char *needle, size_t len);

int			ft_pwd(void);
int			ft_env(void);
int			ft_echo(t_command *command);
int			builtin_export(char *cmd);
int			ft_cd(t_command *command);
int			ft_unset(t_command *command);

void		ft_custom_free(char **str1, char **str2, char SD);
void		ft_single_free(char **string);
void		ft_double_free(char	**string);
void		ft_triple_free(char	***string);

char		**ft_gc_split(char const *s, char c);
char		*ft_gc_strjoin(char const *s1, char const *s2);

t_command	*ft_commandaddback(t_command **lst, t_command *new);
t_command	*ft_newcommand(char *command);
t_command	*ft_get_last_command(t_command *lst);
void		ft_increase_i_quote_handler(char *cmd, int *i, int *quote);
void		ft_inc_uqh(
				char *cmd, unsigned int *i, int *quote);
void		ft_toggle_quote(int *quote_toggle);
int			ft_strlen_not_quoted(char *str, char const *set);

t_envlist	*ft_setenv(char *key, char *value);
t_envlist	*ft_find_envlist(char *key);
t_envlist	*ft_new_list(char *f, char *n, char *c, char **envp);
void		ft_env_addback(t_envlist **lst, t_envlist *new);
int			ft_del_envlist(char *key_to_delete);

char		*ft_get_nice_prompt(void);
void		set_shell_envvariable(void);

t_files		*ft_create_file_list(char *command);
void		ft_print_files(t_files *files);
char		*ft_translate_envs(char *command);
char		*ft_insert_exit_code(char *command);

void		ft_increase_i_singlequote_handler(
				char *cmd, int *i, int *quote);
void		ft_incs_uihand(char *cmd, unsigned int *i, int *quote);
char		*ft_strnstr_nowhere_quotes(
				const char *haystack, const char *needle, size_t len);
void		ft_singlequote_handler(char *cmd, int *quote);

int			ft_set_most_recent_exit_code(int exit_code, int set);
char		*ft_strnstr_single_quotes(
				const char *haystack, const char *needle, size_t len);
void		ft_single_double_quote_handler(
				char *cmd, int *i, int *dq, int *sq);
void		ft_usdq_handler(
				char *cmd, unsigned int *i, int *dq, int *sq);
int			ft_strlen_not_any_quoted(char *str, char const *set);

t_files		*ft_new_file(char *filename, char *path, int in, int out);
t_command	*ft_check_infile(t_command *command, char *command_section);

int			ft_strnstr_pos(const char *haystack,
				const char *needle, size_t len);
int			ft_strnstr_now_quotes_pos(const char *haystack,
				const char *needle, size_t len);
int			ft_append_or_out(t_command *command);

char		*ft_gc_strrev(char *string);

int			ft_increase_until_change(int *q1, int *q2, int *q3, char *temp);

void		ft_strncincrtotaluihand(char *command, t_envit *h);
char		*ft_increase_and_return_quote(t_gnw_splint *gnw,
				unsigned int *i, unsigned int *saved);
void		ft_command_debug(t_command *start);
void		ft_strinc_exitcode_aux(char *command, t_exit_code_aux *h);
int			ft_file_count(char **argv);
t_fs_aux	*ft_new_split_aux(char *cmd);
void		ft_fs_skip_to_quote_end(t_fs_aux *fs_aux, unsigned int *i);
void		ft_fs_skip_until_notinset(t_fs_aux *fs_aux,
				unsigned int *i, char *set);
char		*ft_return_cq_filename(t_fs_aux *fx, unsigned int *i,
				char *set, unsigned int saved);
t_files		*ft_filelist_returnval(t_files *start, t_files *files);
#endif
