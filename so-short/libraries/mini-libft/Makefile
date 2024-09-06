# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 03:31:05 by gicomlan          #+#    #+#              #
#    Updated: 2024/09/06 16:47:00 by gicomlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_so_long.a

CC = cc -Wall -Wextra -Werror

SRC = 	ft_strlen.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		../get_next_line/get_next_line.c \
		../get_next_line/get_next_line_utils.c \
		../ft_printf/ft_printf.c \
		../ft_printf/ft_printf_hexa.c \
		../ft_printf/ft_printf_ptr.c \
		../ft_printf/ft_printf_unsign.c \
		../ft_printf/ft_printf_nbr.c \
		../ft_printf/ft_printf_str.c

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

BOLD 					= \e[1m
DIM 					= \e[2m
ITALIC					= \e[3m
UNDERLINE 				= \e[4m
BLINK					= \e[5m
REVERSE					= \e[7m
HIDDEN					= \e[8m
STRIKE					= \e[9m
RESET 					= \e[0m

TOTAL_SRCS_FILES 	:= $(words $(SRC))
PROGRESS_BAR_SIZE	:= 50
COMPILED_SRCS_FILES	:= 0
PROGRESS_UNICODE	:= █
REMAINING_UNICODE	:= ▒

COMP_START	=	echo "\n🚧 $(BOLD)Making of $(RESET)$(PURPLE)$(NAME)$(NO_COLOR): compilation of $(UNDERLINE)*.o$(RESET) done\n"

CLEANED		=	echo "\n💧 $(BOLD)Cleanning of $(RESET)$(GREEN)$(ITALIC)$(UNDERLINE)$(NAME)$(RESET)$(NO_COLOR): $(DIM)Removed$(RESET) all the $(STRIKE)\".o\"$(RESET) files 🗑\\n"

FCLEANED	=	echo "\n🧼 $(BOLD)Fcleanning of $(RESET)$(GREEN)$(ITALIC)$(UNDERLINE)$(NAME)$(RESET)$(NO_COLOR): $(DIM)Removed$(RESET) the $(STRIKE)executables$(RESET) 🗑\\n"

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS) > /dev/null 2>&1
	@ranlib $(NAME)
	$(COMP_START)

%.o: %.c
	@$(CC) -c $< -o $@ > /dev/null 2>&1
	@$(call progress_bar)

clean :
	@rm -f $(OBJS)
	$(CLEANED)

fclean : clean
	@rm -f $(NAME)
	$(FCLEANED)

re : fclean all

.PHONY : all clean fclean re

define progress_bar
    @$(eval COMPILED_SRCS_FILES := $(shell expr $(COMPILED_SRCS_FILES) + 1))
    @printf "⚙️  "
    @$(eval PROGRESS := $(shell expr $(COMPILED_SRCS_FILES) \* $(PROGRESS_BAR_SIZE) / $(TOTAL_SRCS_FILES)))
    @$(eval REMAINING := $(shell expr $(PROGRESS_BAR_SIZE) - $(PROGRESS)))
    @printf "$(RED)%$(PROGRESS)s$(NO_COLOR)" | sed 's/ /$(PROGRESS_UNICODE)/g'
    @printf "$(BLUE)%$(REMAINING)s$(NO_COLOR)" | sed 's/ /$(REMAINING_UNICODE)/g'
    @printf " (%.2f%%) [%d/%d] %s" \
        $(shell echo "scale=2; $(COMPILED_SRCS_FILES)/$(TOTAL_SRCS_FILES) * 100" | bc) \
        $(COMPILED_SRCS_FILES) $(TOTAL_SRCS_FILES) $(notdir $<)
    @printf "\033[0K\r"
endef
