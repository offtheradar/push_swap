# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 12:24:30 by ysibous           #+#    #+#              #
#    Updated: 2018/04/19 12:33:07 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o

FILES = main.c
FILES += parse_command.c
FILES += ../stack/stack.c
FILES += ../stack/basic_stack_ops.c
FILES += ../stack/check_stack.c

all: $(NAME)

LIBFT = ../../includes/libft/libft.a

mlibft.a: 
		make -C ../ -C ../ -C includes -C libft

$(NAME): mlibft.a
	$(CC) $(CFLAGS) $(NAME) $(FILES) $(LIBFT)


