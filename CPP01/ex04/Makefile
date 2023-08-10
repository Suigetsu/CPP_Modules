# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 12:11:25 by mlagrini          #+#    #+#              #
#    Updated: 2023/08/10 18:36:40 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	main.cpp Sed.cpp
OBJ		=	${SRC:.cpp=.o}
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
NAME	=	sed
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