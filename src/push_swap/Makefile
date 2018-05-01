# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 12:40:43 by ysibous           #+#    #+#              #
#    Updated: 2018/04/30 20:02:24 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang -g
CFLAGS = -Wall -Wextra -Werror -o

FILES = main.c
FILES += sort.c
FILES += sort_3.c
FILES += ../stack/stack.c
FILES += ../stack/basic_stack_ops.c
FILES += ../stack/check_stack.c
FILES += ../checker/parse_command.c

all: $(NAME)

LIBFT = ../../includes/libft/libft.a

mlibft.a:
		make -C ../ -C ../ -C includes -C libft

$(NAME): mlibft.a
	$(CC) $(CFLAGS) $(NAME) $(FILES) $(LIBFT)
