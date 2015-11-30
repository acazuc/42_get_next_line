# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2015/11/26 13:25:04 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

FLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $^ -L libft/ -lft

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

.PHONY: clean fclean re

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
