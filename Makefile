# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 14:38:56 by jiwolee           #+#    #+#              #
#    Updated: 2022/03/22 14:39:00 by jiwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIB_DIR	= ./libft/
LIB		= $(LIB_DIR)libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

AR		= ar
ARFLAGS = rus

HEADER = ft_printf.h

SRCS = ft_printf.c \
		prtf_form_1.c \
		prtf_form_2.c \
		prtf_apply_flgs_1.c \
		prtf_apply_flgs_2.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

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
