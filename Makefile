# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 13:07:03 by mshereme          #+#    #+#              #
#    Updated: 2023/12/19 20:24:28 by mshereme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = libix

NAME_BONUS = bonus

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror -g3

LIBFTDIR = libft/

MINIDIR = minilibx-linux/

SRC = src/main.c \

OBJ = ${SRC:.c=.o}

INCLUDE = -L ./libft -lft

MINI = -L ./minilibx-linux -lmlx -lXext -lX11

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	make -C ${LIBFTDIR}
	make -C ${MINIDIR}
	${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE} ${MINI}
	@echo "${NAME}: $(GREEN)$(NAME) was created$(RESET)"

all: ${NAME}

clean:
	${RM} ${OBJ} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@echo "${NAME}: $(RED)${NAME} was deleted$(RESET)"

fclean: clean
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus
