# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 13:34:53 by olgerret          #+#    #+#              #
#    Updated: 2021/09/30 16:00:16 by jfritz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_philosophers.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_philosophers.c ft_error_checkers.c ft_helpers.c \
    ft_input_handling.c
all: $(NAME)
$(NAME): *.c
    $(CC) $(FLAGS) -c $(SRC)
    ar rc $(NAME) *.o
    $(CC) $(FLAGS) -L. -lft_philosophers -o philo
clean:
    rm -f *.o
fclean: clean
    rm -f $(NAME)
re: fclean $(NAME)