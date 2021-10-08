CC = gcc

NAME = libft_minishell.a

SRC = main.c ft_prompt.c

#LDFLAGS="-L/opt/homebrew/opt/readline/lib"
#CPPFLAGS="-I/opt/homebrew/opt/readline/include"

#LDFLAGS="-L$(HOME)/.brew/opt/readline/lib"
#CPPFLAGS="-I$(HOME)/.brew/opt/readline/include"
LDFLAGS="-L/Users/$(USER)/.brew/opt/readline/lib"
CPPFLAGS="-I/Users/$(USER)/.brew/opt/readline/include"

CFLAGS = -g -lreadline $(LDFLAGS) $(CPPFLAGS) -ltermcap -Wall -Wextra -Werror

all: $(NAME)

$(NAME): *.c
	make -C libft/
	cp ./libft/libft.a ${NAME}
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	$(CC) $(CFLAGS) -L. -lft_minishell -o minishell

clean:
	rm -f ./libft/*.o
	rm -f *.o

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME) minishell

re: fclean $(NAME)
