# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 18:11:57 by mlagrini          #+#    #+#              #
#    Updated: 2023/08/27 20:37:47 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJ		=	${SRC:.cpp=.o}
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic 
RM		=	rm -rf
NAME	=	a.out

all: ${NAME}

%.o:%.cpp
		${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
		${CC} ${FLAGS} ${OBJ} -o ${NAME}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}
		
re:		fclean all

.PHONY:	all clean fclean re
