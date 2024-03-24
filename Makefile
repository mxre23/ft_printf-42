# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmore-oj <jmore-oj@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 20:35:00 by jmore-oj          #+#    #+#              #
#    Updated: 2024/03/24 19:28:50 by jmore-oj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchr.c ft_putstrr.c ft_putnbrr.c ft_puthex.c

HEADER = ft_printf.h

OBJ = ${SRC:.c=.o}

INCLUDE = ft_printf.h Makefile

all: ${NAME}


${NAME}: ${OBJ}
	ar -rcs ${NAME} ${OBJ}


%.o: %.c ${HEADER} Makefile
	${CC} ${CFLAGS} -c  $< -o $@

clean: 
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
