# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nranna <nranna@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 12:06:45 by nranna            #+#    #+#              #
#    Updated: 2024/04/09 23:26:29 by nranna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror
LIBXFLAGS = -L. -lXext -L. -lX11 -lm
NAME = executable
COLOR_GREEN = \033[1;32m

# \/--[minilibx path here]--\/
MINILIBX_PATH = ./minilibx_linux
# /\ -------- /\ ---------- /\

MINILIBX = ${MINILIBX_PATH}/libmlx.a

# PROGRAM FILES
SRC = frac.c string_utils.c init.c math_utils.c render.c
INCLUDE = h_fractal.h

OBJ = $(SRC:.c=.o)

all: $(NAME)
%.o: %.c $(INCLUDE)
	@$(CC) $(CCFLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(MINILIBX)
	@echo "CREATING PROGRAM [$(NAME)]"
	@$(CC) $(CCFLAGS) $(OBJ) $(MINILIBX) $(LIBXFLAGS) -o $(NAME)
	@echo "\n$(COLOR_GREEN)DONE :)\n"
clean:
	@echo "CLEANING OBJECT FILES..."
	@rm -f $(OBJ)

fclean: clean
	@echo "CLEANING [$(NAME)]..."
	@rm -f $(NAME)
	@echo "\nDONE :)"

re: fclean all

.PHONY: all clean fclean re
