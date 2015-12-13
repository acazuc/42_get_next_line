# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2015/12/13 13:47:19 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

FLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@Make -F libft
	@gcc $(FLAGS) -o $(NAME) $^ -L libft/ -lft

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

.PHONY: clean fclean re

clean:
	@Make clean -C libft
	@rm -f $(OBJS)

fclean: clean
	@Make fclean -C libft
	@rm -f $(NAME)

re: fclean all
