# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsauvage <lsauvage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 16:45:25 by lsauvage          #+#    #+#              #
#    Updated: 2018/01/18 15:33:15 by lsauvage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

SRC = srcs/main.c srcs/map.c srcs/reader.c srcs/solver.c srcs/tetrimino.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I libft/libft.h -I includes/fillit.h

LIBS = -L libft/ -lft

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ re
	@$(CC) -o $(NAME) $(OBJ) $(LIBS)
	@echo "\033[33m...\033[0m"

$(OBJ):
	@echo "\033[33m...compiling FILLIT sources...\033[0m"
	@$(CC) $(FLAGS) $(INCLUDES) -c $(SRC)

clean:
	@echo "\033[33m...removing object files... \033[0m"
	@/bin/rm -f $(OBJ)
	@echo "\033[32m[OK]\033[0m \033[33m all .o files are removed ! \033[0m"

fclean: clean
	@echo "\033[33m...removing $(NAME)... \033[0m"
	@/bin/rm -f $(NAME)
	@echo "\033[32m[OK]\033[0m \033[31m$(NAME) is deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re
