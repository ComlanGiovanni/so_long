# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 03:27:53 by gicomlan          #+#    #+#              #
#    Updated: 2024/08/06 12:01:35 by gicomlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc -Wall -Wextra -Werror

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
	@ar rc $(NAME) $(OBJS)

bonus: $(NAME) $(OBJS_BONUS)
	@ar rc $(NAME) $(OBJS_BONUS)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
