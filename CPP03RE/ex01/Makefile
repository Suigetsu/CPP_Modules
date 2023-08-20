# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 15:59:03 by mlagrini          #+#    #+#              #
#    Updated: 2023/08/20 16:26:33 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ		=	${SRC:.cpp=.o}
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
RM		=	rm -rf
NAME	=	ScavTrap

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