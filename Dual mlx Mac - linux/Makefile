# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 23:13:29 by gcomlan           #+#    #+#              #
#    Updated: 2022/07/25 15:13:27 by gcomlan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=mlxstart

INC_PATH := ./includes/

SRC_PATH := ./src/

OBJ_PATH := ./obj/

GCC := gcc -Wall -Werror -Wextra -g

INC_FLAGS := -I$(INC_PATH)

SRC := $(wildcard $(SRC_PATH)*.c)

OBJ := $(addprefix $(OBJ_PATH),$(notdir $(SRC:.c=.o)))

OS := $(shell uname)

LINUX_PATH := ./MLX_LINUX/

LINUX_FLAGS := -L$(LINUX_PATH) -lmlx -lXext -lX11

MAC_PATH := ./MLX_MAC/

MAC_FLAGS := -L$(MAC_PATH) -lmlx -framework OpenGL -framework AppKit

RM			= rm -f

ifeq ($(OS),Darwin)
	MLX_PATH = $(MAC_PATH)
	MLXFLAGS = $(MAC_FLAGS)
else ifeq ($(OS),Linux)
	MLX_PATH = $(LINUX_PATH)
	MLXFLAGS = $(LINUX_FLAGS)
else
$(error Incompatable OS Detected Linux and Mac os only)
endif

MLX := $(MLX_PATH)libmlx.a

INC_FLAGS += -I$(MLX_PATH)

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(GCC) $(OBJ) $(INC_FLAGS) $(MLXFLAGS) -o $(NAME)

$(MLX):
	make -C $(MLX_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c | $(OBJ_PATH)
	$(GCC) $(INC_FLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	make clean -s -C $(MLX_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all