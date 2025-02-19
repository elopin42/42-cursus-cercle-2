NAME = libftprintf.a

CC = cc 
CFLAGS = -I${INCLUDES} -Wall -Werror -Wextra

INCLUDES = ./
SRCS = 	./ft_printf.c \
			./ft_print_int.c \
			./ft_print_char.c \
			./ft_print_string.c \
			./ft_print_adress.c \

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar -cr ${NAME} ${OBJS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re : fclean all