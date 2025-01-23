# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elopin <elopin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 22:42:51 by elopin            #+#    #+#              #
#    Updated: 2025/01/22 20:40:32 by elopin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g3
NAME = so_long

SRCS = srcs/so_long.c \
	   srcs/check.c \
	   gnl/get_next_line.c \
	   gnl/get_next_line_utils.c \
	   srcs/ft_split.c \
	   srcs/valid.c \
	   srcs/meca.c \
	   srcs/meca2.c \
	   srcs/meca3.c \
	   srcs/meca4.c \

INCL	= -I. -I/usr/include -Imlx -Iprintf
MFLAGS	= -lmlx_Linux -lXext -lX11 -lm -lz -Lmlx -L/usr/lib
MLX		= mlx/libmlx_Linux.a
PRINTF  = printf/libftprintf.a

OBJS = $(SRCS:.c=.o)


all: ${NAME}

$(NAME): $(OBJS) $(MLX) $(PRINTF)
		$(CC) $(CFLAGS) $(OBJS) $(MLX) $(PRINTF) $(MFLAGS) -o $(NAME) 

$(MLX):
	make -C mlx

$(PRINTF):
	make -C printf

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I. -c $< -o $@ $(INCL)

clean:
		rm -f ${OBJS}
		make -C mlx clean
		make -C printf clean

fclean: clean
		rm -f $(NAME)
		make -C mlx clean
		make -C printf fclean

re:		fclean all

.PHONY: all clean fclean re /
