# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elopin <elopin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 00:45:33 by elopin            #+#    #+#              #
#    Updated: 2025/02/18 02:44:11 by elopin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
INCL = -I.

SERVER = server
CLIENT = client

SRCS_SERVER = srcs/server.c
SRCS_CLIENT = srcs/client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(PRINTF) $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF) -o $(CLIENT)

$(PRINTF):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

