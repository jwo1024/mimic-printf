# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 17:39:05 by jiwolee           #+#    #+#              #
#    Updated: 2022/02/23 15:44:12 by jiwolee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIB_DIR	= ./libft/
LIB		= $(LIB_DIR)libft.a
LIB_O 	= $(LIB_DIR)*.o #와일드 카드 쓰지 x

CC		= cc #gcc -> cc
CFLAGS	= -Wall -Wextra -Werror #cflag -> cflags

AR		= ar
ARFLAGS = rus

HEADER = ft_printf.h

SRCS = ft_printf.c \
		prtf_form_1.c \
		prtf_form_2.c \
		prtf_apply_flgs.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(LIB_O) : $(LIB)

$(LIB) :
	make all -C $(LIB_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

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