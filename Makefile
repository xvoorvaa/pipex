# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/15 18:01:23 by xvoorvaa      #+#    #+#                  #
#    Updated: 2021/12/21 13:36:05 by xander        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
NAME_EXE		=	pipex_exe
CFLAGS			=	-Wall -Werror -Wextra
LEAKS			=	-g3 -fsanitize=address
OBJS			=	$(SRCS:.c=.o)
SRCS			=	pipex.c \
					SRC/libft/ft_strjoin.c \
					SRC/libft/ft_strlen.c \
					SRC/libft/ft_strdup.c \
					SRC/libft/ft_strchr.c \
					SRC/libft/ft_bzero.c \
					SRC/libft/ft_calloc.c \
					SRC/libft/ft_split.c \
					SRC/libft/ft_substr.c \
					SRC/libft/ft_strncmp.c \
					SRC/error_management.c \
					SRC/utils.c \
					SRC/child.c \


GREEN			=	\033[1;32m
BLUE			=	\033[1;36m
RED				=	\033[0;31m
NC				=	\033[0m # No Color

START			= "$(BLUE)---\nStarting...!\n---$(NC)"
MESSAGE			= "$(BLUE)---\nCompiling done! Run ./$(NAME)\n---$(NC)"
COMP_MESSAGE	= "$(GREEN)Building C object... $(NC)%-33.33s\r\n"
REM_MESSAGE		= "$(RED)Removing files...$(NC)"

all:		$(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME_EXE) $(OBJS)
	@clear
	@echo $(START)
	@gcc $(CFLAGS) $(NAME_EXE) -o $(NAME)
	@printf $(COMP_MESSAGE) $(SRCS)
	@echo $(MESSAGE)

leaks:
	@echo $(START)
	@gcc $(CFLAGS) $(SRCS) $(LEAKS) -o $(NAME)
	@printf $(COMP_MESSAGE) $(SRCS)
	@rm -rf $(OBJS) $(NAME_EXE)
	@echo $(MESSAGE)

clean:
	@echo "\n"
	@rm -f $(OBJS)
	@printf $(REM_MESSAGE)
	@echo "\n"


fclean:		clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@rm -rf $(NAME_EXE)

re:			fclean all

.PHONY:		all leaks clean fclean re
