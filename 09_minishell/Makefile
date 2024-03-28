NAME		=	minishell

INC		=	./minishell.h

CC		=	clang

CFLAGS		=	-Wall -Wextra -Werror

CFA		=	-fsanitize=address -g3

RM		=	/usr/bin/rm -rf


SRC		=	main.c \
			ft_strings.c \
			ft_check.c \
            		ft_exit.c \
			ft_sig.c \
			ft_split.c\
			ft_split_quote.c \
			ft_split_pipe.c \
			init.c \
			redir.c \
			redir2.c \
			redirections.c \
			redirections2.c \
			ft_tab_redir.c \
			ft_dollar.c \
			ft_dollar_int.c \
			forpipe.c\
			forpipe2.c\
			ft_fre.c \
			builtins/builtin_echo.c \
			builtins/builtin_env.c \
			builtins/builtin_export.c \
			builtins/builtin_export_replace.c \
			builtins/builtin_export_var.c \
			builtins/builtin_pwd.c \
			builtins/builtin_cd.c \
			builtins/builtin_unset.c \
			builtins/env_shlvl.c \
			utils/ft_putstr_fd.c \
			utils/ft_strdup.c \
			utils/ft_strncmp.c \
			utils/strcmp.c \
			utils/ft_strjoin_lib.c \
			utils/ft_itoa.c \
			utils/ft_strcat.c \
			utils/ft_nb_char.c \
			utils/ft_free_inpt.c \
			utils/is_only_chevron.c\

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) -lreadline $(SRC)

%.o		:	%.c
			$(CC) $(CFLAGS) -o $@ -c  $<

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

fsa		:	fclean $(OBJ)
			$(CC) $(CFLAGS) $(CFA) -o $(NAME) -lreadline $(SRC) 

re		:	fclean all

.PHONY		:		all n clean fclean fsa re
