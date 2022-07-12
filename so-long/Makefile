# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 01:52:41 by gcomlan           #+#    #+#              #
#    Updated: 2022/07/12 19:21:07 by gcomlan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror -g

NAME		=	so_long

LIB_NAME	=	lib_so_long.a

CHECKER_NAME	= so_long

RM			= rm -f

#Files
SRC		=	main.c \
			./src/src.c

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

SO_LONG_COMP	=	echo "\n🚧 $(YELLOW)so_long: $(NO_COLOR)Starting the compilation...\n"

SO_LONG_READY	=	echo "\n🧮 $(RED)so_long $(NO_COLOR)ready!\n"

BONUS_READY	=	echo "\n🎯 Bonus: $(CYAN)checker $(NO_COLOR)ready!\n"

CLEANED		=	echo "\n💧 $(GREEN)Clean: $(NO_COLOR)Removed all the \".o\" files 🗑\\n"

FCLEANED	=	echo "\n🧼 $(GREEN)Fclean: $(NO_COLOR)Removed the executables 🗑\\n"

NEW_LINE	=	echo "\n"

# ------------------------------ Rules ---------------------------------

all : $(NAME)

$(NAME):
	make -C ./libs/lib
	cp ./libs/lib/$(LIB_NAME) .
	@$(SO_LONG_COMP)
	$(GCC) $(SRC) -L. $(LIB_NAME) -o $(NAME)
	@echo "$$HEADER"
	@$(SO_LONG_READY)

bonus: $(OBJS_BONUS)
	make -C ./libs/lib
	cp ./lib/libpushswap.a ./bonus
	$(GCC) $(SRCS_BONUS) -L. ./bonus/$(LIB_NAME) -o $(CHECKER_NAME)
	@$(BONUS_READY)

clean :
	$(RM) *.o
	$(RM) *~
	$(RM) *#
	$(RM) ./bonus/*.o
	make -C ./libs/lib clean
	@$(CLEANED)

fclean : clean
	rm -f $(NAME)
	make -C ./libs/lib fclean
	rm -f $(LIB_NAME)
	rm -f ./bonus/$(LIB_NAME)
	rm -f $(CHECKER_NAME)
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