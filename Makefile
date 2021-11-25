CC = clang

NAME = libft_minishell.a

SRC = main.c setup_shell.c

OUTFILES = compiled/

BUILTINS = ./builtins/ft_pwd.c ./builtins/ft_env.c ./builtins/ft_echo.c ./builtins/ft_export.c ./builtins/ft_cd.c ./builtins/ft_unset.c

ENV = ./envlist/ft_init_env_list.c ./envlist/ft_env_list.c ./envlist/ft_find_env.c \
       ./envlist/ft_env_addback.c envlist/ft_setenv.c ./envlist/ft_del_envlist.c

PATHS = ./path_helpers/ft_check_paths.c ./path_helpers/ft_check_file_exists.c

PIPEX = ./pipex/ft_minishell_pipex.c ./pipex/ft_pipex_utils.c

HELPERS = ./free_functions/ft_free_functions.c ./arg_printer.c

PARSING = ./parsing/ft_parsing.c ./parsing/ft_splint.c ./parsing/ft_command_size.c ./parsing/ft_parsing_aux.c \
          ./parsing/ft_get_cmd_filename.c ./parsing/ft_get_last_command.c ./parsing/ft_detect_mredirections.c \
		  ./parsing/ft_set_builtin.c ./parsing/ft_toggle_quote.c ./parsing/ft_flags.c ./parsing/ft_add_files.c \
		  ./parsing/ft_strlen_not_quoted.c ./parsing/ft_set_heredoc.c ./parsing/ft_strnstr_quotes.c

FLAGS = -Wall -Wextra -Werror -g

GARBAGE_COLLECTOR = ./gc/ft_free.c ./gc/ft_freeall.c ./gc/ft_gclststart.c ./gc/ft_malloc.c ./gc/ft_gc_memdup.c

GC_LIBFT_VARIATIONS = ./helper/ft_gc_split.c ./helper/ft_gc_strjoin.c ./helper/ft_gc_strdup.c \
./helper/ft_gc_substr.c ./helper/ft_gc_strtrim.c

COMMANDLIST = ./parsing/ft_newcommand.c ./parsing/ft_commandaddback.c

PROMPT = ./prompt/ft_nice_prompt.c ./prompt/ft_set_shellname.c

DEBUGGING = ./debug_help/ft_translate_flags.c ./debug_help/ft_print_files.c

STRHELPER = ./helper/strhelper/ft_strtouppercase.c ./helper/strhelper/ft_strtolowercase.c ./helper/ft_spongebob_strncmp.c

FILELIST = ./filelist/ft_create_file_list.c ./filelist/ft_multi_splint.c ./parsing/ft_file_splitter.c

ENV_VARS = ./env_vars/ft_translate_envs.c

# from home
ifeq ($(USER), jonathanfritz)
	LDFLAGS="-L/opt/homebrew/opt/readline/lib"
	CPPFLAGS="-I/opt/homebrew/opt/readline/include"
else ifeq ($(USER), cassini)
	LDFLAGS="-L/opt/homebrew/opt/readline/lib"
	CPPFLAGS="-I/opt/homebrew/opt/readline/include"
else # from cluster imacs
	LDFLAGS="-L/Users/$(USER)/.brew/opt/readline/lib"
	CPPFLAGS="-I/Users/$(USER)/.brew/opt/readline/include"
endif

ifeq ($(jfritzmacbookpro), YES)
	LDFLAGS="-L/usr/local/opt/readline/lib"
	CPPFLAGS="-I/usr/local/opt/readline/include"
endif

CFLAGS = -g -lreadline $(LDFLAGS) $(CPPFLAGS) -ltermcap

ALLSRC = $(SRC) $(BUILTINS) $(ENV) $(HELPERS) $(PIPEX) $(PROMPT) $(COMMANDLIST) $(PATHS) $(DEBUGGING) \
$(STRHELPER) $(PARSING) $(GARBAGE_COLLECTOR) $(GC_LIBFT_VARIATIONS) $(FILELIST) $(ENV_VARS)


all: $(NAME)

$(NAME): *.c
	make -C libft/
	cp ./libft/libft.a ${NAME}
	$(CC) $(FLAGS) -D DEBUG=0 -c $(ALLSRC)
	ar rc $(NAME) *.o
	$(CC) $(CFLAGS) $(FLAGS) -L. -lft_minishell -o minishell
	mkdir -p $(OUTFILES)
	mv *.o $(OUTFILES)

debug: *.c
	make -C libft/
	cp ./libft/libft.a ${NAME}
	$(CC) $(FLAGS) -D DEBUG=1 -c $(ALLSRC)
	ar rc $(NAME) *.o
	$(CC) $(CFLAGS) $(FLAGS) -L. -lft_minishell -o minishell
	mkdir -p $(OUTFILES)
	mv *.o $(OUTFILES)
	
debug_no_flags: *.c
	make -C libft/
	cp ./libft/libft.a ${NAME}
	$(CC) -D DEBUG=1 -c $(ALLSRC)
	ar rc $(NAME) *.o
	$(CC) $(CFLAGS) -L. -lft_minishell -o minishell
	mkdir -p $(OUTFILES)
	mv *.o $(OUTFILES)

clean:
	rm -f ./libft/*.o
	rm -f *.o
	rm -rf $(OUTFILES)

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME) minishell

re: fclean $(NAME)
