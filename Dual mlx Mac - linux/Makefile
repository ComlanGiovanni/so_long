# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 22:03:46 by gcomlan           #+#    #+#              #
#    Updated: 2022/07/24 22:07:04 by gcomlan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	mlxstart

INC 	:= 	./includes/

SRCDIR 	:= 	./src/

OBJDIR 	:= 	./obj/

LIBS 	:=

CC 		:= gcc

FLAGS 	:= -Wall -Werror -Wextra -I$(INC) $(LIBS)

SRC 	:= $(wildcard $(SRCDIR)*.c)

OBJ 	:= $(addprefix $(OBJDIR),$(notdir $(SRC:.c=.o)))

OS 		:= $(shell uname)

LINUXDIR 	:= ./MLX_LINUX/
LINUXFLAGS 	:= -L$(LINUXDIR) -lmlx -lXext -lX11

MACDIR 		:= 	./MLX_MAC/
MACFLAGS 	:= -L$(MACDIR) -lmlx -framework OpenGL -framework AppKit

ifeq ($(OS),Darwin)
	MLXDIR = $(MACDIR)
	MLXFLAGS = $(MACFLAGS)
else ifeq ($(OS),Linux)
	MLXDIR = $(LINUXDIR)
	MLXFLAGS = $(LINUXFLAGS)
else
$(error Incompatable OS Detected)
endif

MLX 	:= 	$(MLXDIR)libmlx.a
FLAGS 	+= -I$(MLXDIR)

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(CC) $(OBJ) $(FLAGS) $(MLXFLAGS) -o $(NAME)

$(MLX):
	@make -C $(MLXDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@make clean -s -C $(MLXDIR)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all