# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 17:15:37 by mlagrini          #+#    #+#              #
#    Updated: 2023/11/17 15:19:47 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	main.cpp Span.cpp
OBJ		=	${SRC:.cpp=.o}
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
NAME	=	span
RM		=	rm -rf

all:	${NAME}

%.o:%.cpp Span.hpp
		${CC} ${FLAGS} -c $< -o $@
${NAME}: ${OBJ}
		${CC} ${FLAGS} ${OBJ} -o ${NAME}
		
clean:
		${RM} ${OBJ}

fclean:	clean
		${RM} ${NAME}
		
re:		fclean all

.PHONY: all clean fclean re
