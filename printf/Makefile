# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 10:55:27 by gcomlan           #+#    #+#              #
#    Updated: 2022/06/09 14:35:22 by gcomlan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

SRC =	ft_printf.c \
		ft_printf_hexa.c \
		ft_printf_ptr.c \
		ft_printf_unsign.c \
		ft_printf_nbr.c \
		ft_printf_str.c

OBJS = $(SRC:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(NAME) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
