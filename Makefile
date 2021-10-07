CC = gcc

NAME = libft_minishell.a

FLAGS = -Wall -Wextra -Werror

SRC = main.c \

# LDFLAGS="-L/opt/homebrew/opt/readline/lib"
# CPPFLAGS="-I/opt/homebrew/opt/readline/include"

ifeq ($(MINISHELL),"YES")
	LDFLAGS="-L/usr/local/opt/readline/lib"
	CPPFLAGS="-I/usr/local/opt/readline/include"
	TESTASDASD="OK"
endif

CFLAGS = -lreadline $(LDFLAGS) $(CPPFLAGS) -ltermcap

all: $(NAME)

$(NAME): *.c
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	$(CC) $(CFLAGS) -L. -lft_minishell -o minishell

dev:
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	$(CC) $(CFLAGS_DEV) -L. -lft_minishell -o minishell

clean:
	rm -f ./libft/*.o
	rm -f *.o

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME)

re: fclean $(NAME)
