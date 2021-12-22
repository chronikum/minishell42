## minishell
### team URGENT

Writing a minimalistic shell with basic builtin commands.
As beautiful as a shell.

## Preambel

Here is an excerpt from wikipedia. You should look into it:
> Escalation of commitment is a human behavior pattern in which an individual or group facing increasingly negative outcomes from a decision, action, or investment nevertheless continues the behavior instead of altering course. The actor maintains behaviors that are irrational, but align with previous decisions and actions.
\
>In sociology, irrational escalation of commitment or commitment bias describe similar behaviors. The phenomenon and the sentiment underlying them are reflected in such proverbial images as "Throwing good money after bad", or "In for a penny, in for a pound", or "It's never the wrong time to make the right decision", or "If you find yourself in a hole, stop digging."

We learned a lot from this project and it is far from perfect. \
We passed with 93% on the eval sheet. \
We did not do any bonusses.

## Small Walkthrough

We are using a very complex and overcomplicated tokenization/lexing systems.
So we are skipping on that. This is a simple, very uncomplete documentation on how we do it. \
The input string is being splitted with awareness on quotes on pipes ``|``

Each command section is being parsed to a linked list with the following information content:
```C
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
```
After that, we run each command. As the command contains all information needed for pipex, pipex only needs to interpret those commands correctly.

Following flags are available:

```C
# define IN 2
# define HERE_DOC 3
# define STDOUT -1
# define PIPE 0
# define OUT 1
# define APPEND 4
# define BUILT_IN 5
# define SYS 6
# define SKIP 8
```

Those represent possible in_flags, out_flags and the builtin_sys_flag which basically tells the shell if it should look the command up in the $PATH or if is a builtin.

## Compilation and debugging mode

Compile the project and the libft dependencies with the command ``make``.

Also, our shell has a debugging mode integrated. Please be aware that it can cause problems sometimes.
\
You can activate it with the command ``make debug``.


## additional

We have a garbage collector which basically makes sure that no orphans are being created. It keeps track of everything being allocated, at the end it frees all the allocated pointers. \
Still, readline may leak. \
The project was being modified after evaluation to fix things which came up during evaluation.

Do not use the shell in real world environment. This is a project only built for educational purposes and it is neither secure, audited or performant in any way.

### requirements
You need `readline` installed with `brew install readline` to use and make this shell.
Also, mac-only. not tested on linux distributions.

