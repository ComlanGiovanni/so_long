# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 01:52:41 by gcomlan           #+#    #+#              #
#    Updated: 2022/07/20 23:46:25 by gcomlan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ VARIABLES ------------------------------

GCC			= gcc -Wall -Wextra -Werror -g

NAME		=	so_long

LIB_PATH	=	./lib/small_lib

LIB_NAME	=	lib_so_long.a

MLX_PATH	=	./mlx

MLX_NAME	=	libmlx.a

BONUS_PATH	=	./bonus

BONUS_NAME	=	so_long_bonus

FRAME_WORK	=	-framework OpenGL -framework AppKit

RM			= rm -f

# ------------------------------ SRC ------------------------------

SRC		=	main.c \
			./src/input.c \
			./src/map.c \
			./src/so_long.c \
			./src/sprite.c \
			./src/tools.c

SRCS_BONUS	=   ./bonus/main.c \
				./bonus/src/input_bonus.c \
				./bonus/src/map_bonus.c \
				./bonus/src/so_long_bonus.c \
				./bonus/src/sprite_bonus.c \
				./bonus/src/tools_bonus.c \
				./bonus/src/animation_bonus.c \
				./bonus/src/other_tools_bonus.c \
				./bonus/src/load_sprite_bonus.c \
				./bonus/src/load_player_sprite_bonus.c \
				./bonus/src/load_door_sprite_bonus.c \
				./bonus/src/life_management.c \
				./bonus/src/input_fct_bonus.c \
				./bonus/src/map_sprite_bonus.c \
				./bonus/src/player_sprite_direction_bonus.c

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
	
all : $(NAME)

$(NAME):
	make -C $(LIB_PATH)
	cp $(LIB_PATH)/$(LIB_NAME) .
	@$(SO_LONG_COMP)
	make --no-print-directory -C $(MLX_PATH)
	cp $(MLX_PATH)/$(MLX_NAME) .
	$(GCC) -o $(NAME) -L. $(MLX_NAME) -L. $(LIB_NAME) $(SRC) -lXext -lX11 $(FRAME_WORK)
	@echo "$$ASCII_MANDATORY"
	@$(SO_LONG_READY)

bonus: $(OBJS_BONUS)
	$(GCC) -o $(BONUS_NAME) -L. $(MLX_NAME) -L. $(LIB_NAME) $(SRCS_BONUS) -lXext -lX11 $(FRAME_WORK)
	@echo "$$ASCII_BONUS"
	@$(BONUS_READY)

clean :
	$(RM) *.o
	$(RM) *~
	$(RM) *#
	$(RM) $(BONUS_PATH)/src/*.o
	$(RM) $(BONUS_PATH)/*.o
	make -C $(LIB_PATH) clean
	@$(CLEANED)

fclean : clean
	$(RM) $(NAME)
	make -C $(LIB_PATH) fclean
	$(RM) $(LIB_NAME)
	$(RM) $(BONUS_NAME)
	$(RM) $(MLX_NAME)
	@$(FCLEANED)

re : fclean all

# ------------------------------ Ascii ---------------------------------

info: ascii

define ASCII_MANDATORY
$(RED)                       ,         $(NO_COLOR)
$(RED)       ❤            .:/          $(NO_COLOR)
$(RED)         o      ,,///;,   ,;/    $(NO_COLOR)
$(RED)           o   o)::::::;;///     $(NO_COLOR)
$(RED)              >::::::::;;\\\     $(NO_COLOR)
$(RED)                ''\\\\\'" ';\    $(NO_COLOR)
$(RED)                   ';\           $(NO_COLOR)
endef
export ASCII_MANDATORY

define ASCII_BONUS
$(CYAN) o									$(NO_COLOR)
$(CYAN)o      ______/~/~/~/__           /((	$(NO_COLOR)
$(CYAN)  o  // __            ====__    /_((	$(NO_COLOR)
$(CYAN) o  //  @))       ))))      ===/__((	$(NO_COLOR)
$(CYAN)    ))           )))))))        __((	$(NO_COLOR)
$(CYAN)    \\     \)     ))))    __===\ _((	$(NO_COLOR)
$(CYAN)     \\_______________====      \_((	$(NO_COLOR)
$(CYAN)                                 \((	$(NO_COLOR)
endef
export ASCII_BONUS
