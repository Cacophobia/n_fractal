# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nranna <nranna@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 12:06:45 by nranna            #+#    #+#              #
#    Updated: 2024/05/04 21:35:15 by nranna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Ofast #-Wall -Wextra -Werror
LIBXFLAGS = -lmlx_Linux -L./minilibx-linux -lXext -lX11 -lm
NAME = executable
GREEN = \033[1;32m
WHITE = \033[1;37m

# \/--[minilibx path here]--\/
MINILIBX_PATH = ./minilibx-linux
# /\ -------- /\ ---------- /\

MINILIBX = ${MINILIBX_PATH}/libmlx.a

# PROGRAM FILES
SRC = main.c string_utils.c init.c math_utils.c render.c hooks.c
INCLUDE = fractol.h

OBJ = $(SRC:.c=.o)

all: $(NAME)
%.o: %.c $(INCLUDE)
	@$(CC) $(CCFLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(MINILIBX)
	@echo "$(WHITE)\nCREATING [$(NAME)]..."
	@$(CC) $(CCFLAGS) $(OBJ) $(MINILIBX) $(LIBXFLAGS) -o $(NAME)
	@echo "$(GREEN)[$(NAME)] OK :)$(WHITE)\n"
clean:
	@echo "$(WHITE)\nCLEANING OBJECT FILES..."
	@rm -f $(OBJ)
	@echo "$(GREEN)OK. :)$(WHITE)\n"

fclean: clean
	@echo "$(WHITE)\nCLEANING [$(NAME)]..."
	@rm -f $(NAME)
	@echo "$(GREEN)OK. :)$(WHITE)\n"

re: fclean all

.PHONY: all clean fclean re
