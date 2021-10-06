CC = gcc

NAME = libft_minishell.a

FLAGS = -Wall -Wextra -Werror

SRC = main.c \

LDFLAGS=-L/Users/$(USER)/.brew/opt/readline/lib
CPPFLAGS=-I/Users/$(USER)/.brew/opt/readline/include


CFLAGS = -lreadline $(LDFLAGS) $(CPPFLAGS) -ltermcap

all: $(NAME)

$(NAME): *.c
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	$(CC) $(CFLAGS) -L. -lft_minishell -o minishell

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
