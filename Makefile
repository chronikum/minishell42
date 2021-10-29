CC = gcc

NAME = libft_minishell.a

SRC = main.c

BUILTINS = ./builtins/ft_pwd.c ./builtins/ft_env.c ./builtins/ft_echo.c

ENV = ./envlist/ft_init_env_list.c ./envlist/ft_env_list.c ./path_helpers/ft_check_paths.c

PIPEX = ./pipex/ft_pipex.c ./pipex/ft_pipex_utils.c

HELPERS = ./free_functions/ft_free_functions.c ./arg_printer.c

PARSING = ./parsing/ft_parsing.c ./parsing/ft_split_quote.c ./parsing/ft_command_size.c

FLAGS = -Wall -Wextra -Werror -g

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

all: $(NAME)

$(NAME): *.c
	make -C libft/
	cp ./libft/libft.a ${NAME}
	$(CC) $(FLAGS) -c $(SRC) $(BUILTINS) $(ENV) $(HELPERS) $(PIPEX) $(PARSING)
	ar rc $(NAME) *.o
	$(CC) $(CFLAGS) -L. -lft_minishell -o minishell

clean:
	rm -f ./libft/*.o
	rm -f *.o

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME) minishell

re: fclean $(NAME)
