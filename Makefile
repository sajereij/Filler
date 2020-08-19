# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/19 17:36:20 by sreijola          #+#    #+#              #
#    Updated: 2020/08/19 17:54:01 by sreijola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sreijola.filler

SRCS = main.c 
#data.c solve.c

LIB = libft/libft.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft
	@$(GCC) $(SRCS) $(FLAGS) $(LIB) -o $(NAME)
	@echo "Library and filler made"

clean:
	@make -C libft clean
	@echo "Object files removed from libft. Beep-Bop"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "Binaries and object files gone."

re: fclean all
	@echo "All good again"
