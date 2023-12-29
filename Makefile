# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 13:07:03 by mshereme          #+#    #+#              #
#    Updated: 2023/12/28 13:05:14 by mshereme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = libix

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

LIBFTDIR = libft/

MLXDIR = minilibx-linux/

SRC = src/main.c \
      src/initialize.c \
      src/error.c \
      src/event.c \
      src/julia.c \
      src/mandelbrot.c \
      src/other.c \
      src/burningship.c \
      src/color.c \

OBJ = ${SRC:.c=.o}

INCLUDE = -L ./libft -lft

MINI = -L ./minilibx-linux -lmlx -lXext -lX11

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	make -C ${LIBFTDIR}
	make -C ${MLXDIR}
	${CC} ${FLAGS} ${OBJ} -o ${NAME} -lm ${INCLUDE} ${MINI}
	@echo "${NAME}: $(GREEN)$(NAME) was created$(RESET)"

all: ${NAME}

clean:
	${RM} ${OBJ} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd ${MLXDIR} && ${MAKE} clean
	@echo "${NAME}: $(RED)${NAME} was deleted$(RESET)"

fclean: clean
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus
