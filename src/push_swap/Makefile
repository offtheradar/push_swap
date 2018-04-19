# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 12:40:43 by ysibous           #+#    #+#              #
#    Updated: 2018/04/19 12:41:02 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o

FILES = main.c
FILES += sort_3.c
FILES += ../stack/stack.c
FILES += ../stack/basic_stack_ops.c
FILES += ../stack/check_stack.c

all: $(NAME)

LIBFT = ../../includes/libft/libft.a

mlibft.a:
		make -C ../ -C ../ -C includes -C libft

$(NAME): mlibft.a
	(CC) $(CFLAGS) $(NAME) $(FILES) $(LIBFT)
