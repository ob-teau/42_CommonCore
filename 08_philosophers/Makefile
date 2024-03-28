# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alice <acoinus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 18:46:24 by alice             #+#    #+#              #
#    Updated: 2022/04/01 16:43:52 by alice            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRC		=	philosophers.c\
			threads.c\
			loop_checker.c\

OBJ		=	$(SRC:.c=.o)

CC		=	clang

FLAGS	=	-Wall -Wextra -Werror -pthread

FS		=	-fsanitize=address -g3

FT		=	-fsanitize=thread -g

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ)
				$(CC) $(FLAGS) -o $(NAME) $(SRC)

%.o		:	%.c
				$(CC) $(FLAGS) -o $@ -c $<

norme	:
				norminette $(SRC)
				norminette -R CheckDefine philosophers.h

clean	:
				$(RM) $(OBJ)

fclean	:	clean
				$(RM) $(NAME)

re		:	fclean all

s		:	$(OBJ)
				$(CC) $(FLAGS) $(FS) -o $(NAME) $(SRC)

sre		:	fclean s

t		:	$(OBJ)
				$(CC) $(FLAGS) $(FT) -o $(NAME) $(SRC)

tre		:	fclean t

.PHONY	:	all norme clean fclean re
