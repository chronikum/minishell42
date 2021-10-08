# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 13:55:23 by olgerret          #+#    #+#              #
#    Updated: 2021/09/13 17:32:08 by olgerret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft_pipex.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_pipex.c ft_pipex_utils.c ft_free_functions.c ft_pipex_parent.c


all: $(NAME)

$(NAME): *.c
	Make -C ./libft
	cp ./libft/libft.a $(NAME)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	gcc $(FLAGS) ft_pipex.c -L. -lft_pipex -o pipex

clean:
	rm -f ./libft/*.o
	rm -f *.o

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME)

re: fclean $(NAME)
