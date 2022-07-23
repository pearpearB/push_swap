# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 15:03:40 by jabae             #+#    #+#              #
#    Updated: 2022/07/23 16:36:23 by jabae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3

SRCS = push_swap.c \
	parsing.c \
	operation.c \
	method.c \
	sorting.c \
	sorting_small.c \
	utils.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
			make -C libft
			$(CC) $(CFLAGS) -L ./libft -lft $(OBJS) -o $@

%.o :%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -rf $(OBJS)
		make clean -C libft

fclean : clean
		rm -rf $(NAME)
		make fclean -C libft

re : fclean all

.PHONY: all clean fclean re
