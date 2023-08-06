# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 12:06:50 by mlagrini          #+#    #+#              #
#    Updated: 2023/08/06 17:19:38 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ContactClass.cpp PhoneBookClass.cpp ContactSetters.cpp \
			ContactGetters.cpp main.cpp
OBJ		=	${SRC:.cpp=.o}
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
NAME	=	PhoneBook
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