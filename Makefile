# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 17:39:05 by jiwolee           #+#    #+#              #
#    Updated: 2022/02/17 21:57:04 by jiwolee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIB_DIR	= ./libft/
LIB		= $(LIB_DIR)libft.a
LIB_O 	= $(LIB_DIR)*.o

CC		= gcc
CFLAG	= -Wall -Wextra -Werror

AR		= ar
ARFLAGS = rus

HEADER = ft_printf.h

SRCS = ft_printf.c \
		ft_form_1.c \
		ft_form_2.c \
		ft_conv_dec.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(LIB_O) : $(LIB)

$(LIB) :
	make all -C $(LIB_DIR)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_BONUS)
	make $@ -C $(LIB_DIR)

fclean : clean
	rm -f $(NAME)
	make $@ -C $(LIB_DIR)

re : fclean all

bonus : all

$(NAME) : $(LIB) $(OBJS)
	cp $(LIB) $@
	$(AR) $(ARFLAGS) $@ $(OBJS)

.PHONY : all clean fclean re bonus