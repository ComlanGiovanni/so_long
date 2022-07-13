# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 01:52:41 by gcomlan           #+#    #+#              #
#    Updated: 2022/07/13 17:29:26 by gcomlan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror -g

NAME		=	so_long

LIB_PATH	=	./lib/small_lib

LIB_NAME	=	lib_so_long.a

MLX_PATH	=	./minilibx

MLX_NAME	=	libmlx.a

BONUS_PATH	=	./bonus

BONUS_NAME	=	so_long_bonus

FRAME_WORK	=	-framework OpenGL -framework AppKit

RM			= rm -f

#Files
SRC		=	main.c \
			./src/input.c \
			./src/map.c \
			./src/so_long.c \
			./src/sprite.c \
			./src/tools.c

SRCS_BONUS	=   ./bonus/main.c \
				./bonus/truc.c

#Obj
SRC_OBJS		=	$(SRC:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

# ------------------------------ Colors ------------------------------

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(PURPLE)Make: $(NO_COLOR)Starting the compilation...\n"

SO_LONG_COMP	=	echo "\n🚧 $(YELLOW) $(NAME): $(NO_COLOR)Starting the compilation...\n"

SO_LONG_READY	=	echo "\n🧮 $(RED) $(NAME) $(NO_COLOR)ready!\n"

BONUS_READY	=	echo "\n🎯 Bonus: $(CYAN) $(BONUS_NAME) $(NO_COLOR)ready!\n"

CLEANED		=	echo "\n💧 $(GREEN)Clean: $(NO_COLOR)Removed all the \".o\" files 🗑\\n"

FCLEANED	=	echo "\n🧼 $(GREEN)Fclean: $(NO_COLOR)Removed the executables 🗑\\n"

NEW_LINE	=	echo "\n"

# ------------------------------ Rules ---------------------------------

#	@make --no-print-directory -C ft_printf
#	@make --no-print-directory -C mlx lib_so_long.a
# $(GCC) -o $(NAME) $(SRC) -L. $(LIB_NAME) -L. $(MLX_PATH)/$(MLX_NAME) $(FRAME_WORK)
	
all : $(NAME)

$(NAME):
	make -C $(LIB_PATH)
	cp $(LIB_PATH)/$(LIB_NAME) .
	@$(SO_LONG_COMP)
	make --no-print-directory -C $(MLX_PATH)
	cp $(MLX_PATH)/$(MLX_NAME) .
	$(GCC) -o $(NAME) -L. $(MLX_NAME) -L. $(LIB_NAME) $(SRC) $(FRAME_WORK)
	@echo "$$HEADER"
	@$(SO_LONG_READY)

bonus: $(OBJS_BONUS)
	make -C $(LIB_PATH)
	cp $(LIB_PATH)/$(LIB_NAME) $(BONUS_PATH)
	$(GCC) $(SRCS_BONUS) -L. $(BONUS_PATH)/$(LIB_NAME) -o $(BONUS_NAME)
	@$(BONUS_READY)

clean :
	$(RM) *.o
	$(RM) *~
	$(RM) *#
	$(RM) $(BONUS_PATH)/*.o
	make -C $(LIB_PATH) clean
	@$(CLEANED)

fclean : clean
	$(RM) $(NAME)
	make -C $(LIB_PATH) fclean
	$(RM) $(LIB_NAME)
	$(RM) $(BONUS_PATH)/$(LIB_NAME)
	$(RM) $(BONUS_NAME)
	@$(FCLEANED)

re : fclean all

info: header

define HEADER
$(CYAN)                       ,         $(NO_COLOR)
$(CYAN)       ❤            .:/          $(NO_COLOR)
$(CYAN)         o      ,,///;,   ,;/    $(NO_COLOR)
$(CYAN)           o   o)::::::;;///     $(NO_COLOR)
$(CYAN)              >::::::::;;\\\     $(NO_COLOR)
$(CYAN)                ''\\\\\'" ';\    $(NO_COLOR)
$(CYAN)                   ';\            $(NO_COLOR)
endef
export HEADER