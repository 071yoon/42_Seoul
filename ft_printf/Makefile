# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeoyoon <yeoyoon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:47:14 by yeoyoon           #+#    #+#              #
#    Updated: 2022/01/03 14:51:48 by yeoyoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT 	= ./libft/libft.a

NAME	= libftprintf.a

SRCS	= 	ft_printf.c \
			char_format.c \
			hex_format.c \
			int_format.c \
			ptr_format.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc
AR		= ar crs
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			$(AR) $(NAME) $(OBJS)


clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re