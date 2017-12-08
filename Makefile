# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsauvage <lsauvage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 16:45:25 by lsauvage          #+#    #+#              #
#    Updated: 2017/12/01 17:20:48 by lsauvage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

SRC = srcs/main.c srcs/...

OBJ = $(SRC:.c=.o)

INCLUDES = -I libft -I includes

LIBS = -L libft/ -lft

FLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJ)
	@make -C libft/ re
	@$(CC) -o $(NAME) $(OBJ) $(LIBS)
	@echo "\033[33m...\033[0m"

$(OBJ):
	@echo "\033[33m...compiling FILLIT sources...\033[0m"
	@$(CC) $(FLAGS) -c $(SRC)
