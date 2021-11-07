CC = clang

NAME = libft_minishell.a

SRC = main.c

OUTFILES = compiled/

BUILTINS = ./builtins/ft_pwd.c ./builtins/ft_env.c ./builtins/ft_echo.c ./builtins/ft_export.c

ENV = ./envlist/ft_init_env_list.c ./envlist/ft_env_list.c ./envlist/ft_find_env.c \
       ./envlist/ft_env_addback.c envlist/ft_setenv.c

PATHS = ./path_helpers/ft_check_paths.c ./path_helpers/ft_check_file_exists.c

PIPEX = ./pipex/ft_minishell_pipex.c ./pipex/ft_pipex_utils.c

HELPERS = ./free_functions/ft_free_functions.c ./arg_printer.c

PARSING = ./parsing/ft_parsing.c ./parsing/ft_split_quote.c ./parsing/ft_command_size.c ./parsing/ft_parsing_aux.c \
          ./parsing/ft_get_cmd_filename.c ./parsing/ft_get_last_command.c

FLAGS = -Wall -Wextra -Werror -g

GARBAGE_COLLECTOR = ./gc/ft_free.c ./gc/ft_freeall.c ./gc/ft_gclststart.c ./gc/ft_malloc.c

GC_LIBFT_VARIATIONS = ./helper/ft_gc_split.c ./helper/ft_gc_strjoin.c

COMMANDLIST = ./parsing/ft_newcommand.c ./parsing/ft_commandaddback.c

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

CFLAGS = -g -lreadline $(LDFLAGS) $(CPPFLAGS) -ltermcap -Wall -Wextra -Werror

ALLSRC = $(SRC) $(BUILTINS) $(ENV) $(HELPERS) $(PIPEX) $(COMMANDLIST) $(PATHS) $(PARSING) $(GARBAGE_COLLECTOR) $(GC_LIBFT_VARIATIONS)


all: $(NAME)

$(NAME): *.c
	make -C libft/
	cp ./libft/libft.a ${NAME}
	$(CC) $(FLAGS) -D DEBUG=0 -c $(ALLSRC)
	ar rc $(NAME) *.o
	$(CC) $(CFLAGS) -L. -lft_minishell -o minishell
	mkdir -p $(OUTFILES)
	mv *.o $(OUTFILES)

debug: *.c
	make -C libft/
	cp ./libft/libft.a ${NAME}
	$(CC) $(FLAGS) -D DEBUG=1 -c $(ALLSRC)
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
