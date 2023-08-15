# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 18:32:21 by mlagrini          #+#    #+#              #
#    Updated: 2023/08/15 18:32:23 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	main.cpp Fixed.cpp
OBJ		=	${SRC:.cpp=.o}
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
RM		=	rm -rf

%.o:%.cpp
		${CC} ${FLAGS} -c $< -o $@

all: ${OBJ}
		${CC} ${FLAGS} ${OBJ}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} a.out
		
re:		fclean all

.PHONY:	all clean fclean re
