# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 16:33:46 by mlagrini          #+#    #+#              #
#    Updated: 2023/10/03 16:33:46 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJ		=	${SRC:.cpp=.o}
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
NAME	=	forms
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
