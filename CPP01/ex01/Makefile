# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 16:15:01 by mlagrini          #+#    #+#              #
#    Updated: 2023/08/09 17:37:32 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	main.cpp zombieHorde.cpp Zombie.cpp
OBJ		=	${SRC:.cpp=.o}
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
NAME	=	moar_brainz
RM		=	rm -rf

all:	${NAME}

%.o:%.cpp
		${CC} ${FLAGS} -c $< -o $@
${NAME}: ${OBJ}
		${CC} ${FLAGS} ${OBJ} -o ${NAME}
		
clean:
		${RM} ${OBJ}

fclean:	clean
		${RM} ${NAME}
		
re:		fclean all

.PHONY: all clean fclean re