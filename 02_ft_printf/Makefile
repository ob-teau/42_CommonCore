# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoinus <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 14:39:35 by acoinus           #+#    #+#              #
#    Updated: 2021/09/02 16:59:06 by acoinus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

NORME		= norminette .

SRC			= ft_printf.c\
			  ft_width_prec_type.c\
			  libft.c\
			  print_c_s.c\
			  print_nb.c\
			  print_nb_utils.c\

OBJ			= $(SRC:.c=.o)

CC			= gcc

RM			= rm -f

FLAGS		= -Wall -Wextra -Werror

.c.o	:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
			ar rcs $(NAME) $(OBJ)

all		: $(NAME)

bonus	: re

norme	:
	$(NORME)

clean	:
			$(RM) $(OBJ)

fclean	: clean
			$(RM) $(NAME)

re		: fclean all

.PHONY	: all norme clean fclean re
