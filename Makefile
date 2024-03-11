# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmore-oj <jmore-oj@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 20:35:00 by jmore-oj          #+#    #+#              #
#    Updated: 2024/03/11 22:09:55 by jmore-oj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = 

HEADER = ft_printf.h

OBJ = ${SRC:.c=.o}

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
