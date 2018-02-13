# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsauvage <lsauvage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 16:45:25 by lsauvage          #+#    #+#              #
#    Updated: 2018/02/13 17:43:20 by lsauvage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

SRC = srcs/main.c srcs/map.c srcs/reader.c srcs/solver.c srcs/tetrimino.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I libft/libft.h -I includes/fillit.h

LIBS = -L libft/ -lft

FLAGS = -Wall -Werror -Wextra


# PROGRESS BAR
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	printf "%-60b\r" "$(ECHO) $(_PURPLE) Compiling $< $(_END)"

$(NAME): $(OBJ)
	echo "\n"
	make -C libft/
	$(CC) -o $(NAME) $(OBJ) $(LIBS)
	echo "$(_GREEN)[OK] $(NAME) is ready $(_END)"

clean:
	echo "$(_YELLOW)...removing object files... $(_END)"
	make -C libft/ clean
	/bin/rm -f $(OBJ)
	echo "$(_GREEN)[OK]$(_END) $(_YELLOW) all .o files are removed ! $(_END)"

norme: clean
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckForbiddenSourceHeader includes/fillit.h
	norminette -R CheckForbiddenSourceHeader libft/*.c libft/*.h

fclean: clean
	echo "$(_YELLOW)...removing $(NAME)... $(_END)"
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	echo "$(_GREEN)[OK]$(_END) $(_RED)$(NAME) is deleted$(_END)"

re: fclean all

.PHONY: all clean norme fclean re
