# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elopin <elopin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 18:31:05 by elopin            #+#    #+#              #
#    Updated: 2025/02/09 23:21:19 by elopin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=\033[0;32m
RED=\033[0;31m
NC=\033[0m

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
NAME = push_swap

SRCS = srcs/meca.c \
	   srcs/push_swap.c \
	   srcs/prec.c \
	   srcs/pre_meca.c \
	   srcs/utils.c \
	   srcs/prec2.c \
		 srcs/precbo.c \

INCL = -I. -Iprintf
PRINTF = printf/libftprintf.a

OBJS = $(SRCS:.c=.o)

all: logo ${NAME}

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

logo:
		@echo -e "$(GREEN)\
EEEEEEE LL       OOOOO  PPPPPP  IIIII NN   NN\n\
   EE      LL      OO   OO PP   PP  III  NNN  NN\n\
   EEEEE   LL      OO   OO PPPPPP   III  NN N NN\n\
   EE      LL      OO   OO PP       III  NN  NNN\n\
   EEEEEEE LLLLLLL  OOOO0  PP      IIIII NN   NN\n\$(NC)"

$(PRINTF):
	make -C printf

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@ $(INL)
	@echo -e "$(GREEN)Compilation réussie !$(NC)"

clean:
	rm -f ${OBJS}
	make -C printf clean
	@echo -e "$(RED)clean$(NC)"

fclean: clean
	rm -f $(NAME)
	make -C printf fclean
	@echo -e "$(RED)fclean$(NC)"

re:	fclean all

.PHONY: all clean fclean re /
