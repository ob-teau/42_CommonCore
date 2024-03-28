# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoinus <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 16:15:47 by acoinus           #+#    #+#              #
#    Updated: 2022/01/13 11:21:11 by acoinus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRC		=	pipex.c\
			get_path.c\
			libft/ft_split.c\
			libft/ft_strjoin.c\
			libft/ft_strlen.c\
			libft/split_add.c\

OBJ		= $(SRC:.c=.o)

CC		= clang

FLAGS	= -Wall -Wextra -Werror

FS		= -fsanitize=address -g3

RM		= rm -f

all 	: $(NAME) #LIBFT $(NAME)

#LIBFT	:
#				make -C libft

$(NAME)	:	$(OBJ)
				$(CC) $(FLAGS) -o $(NAME) $(SRC)

%.o		:	%.c
				$(CC) $(FLAGS) -o $@ -c $<

norme	:
				norminette $(SRC)
				norminette -R CheckDefine pipex.h

clean	:
			$(RM) $(OBJ)

fclean	:	clean
				$(RM) $(NAME)

re		:	fclean all

s		:	$(OBJ)
				$(CC) $(FLAGS) $(FS) -o $(NAME) $(SRC) $(LIB)

sre		:		fclean s

.PHONY : all norme clean fclean re

