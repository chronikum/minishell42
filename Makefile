NAME = libft_minishell.a
FLAGS = -Wall -Wextra -Werror
SRC = main.c \

all: $(NAME)

$(NAME): *.c
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	$(CC) $(FLAGS) -L. -lft_minishell -o minishell

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
