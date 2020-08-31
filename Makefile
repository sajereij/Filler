# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/19 17:36:20 by sreijola          #+#    #+#              #
#    Updated: 2020/08/25 13:50:48 by sreijola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re fun fil

NAME = sreijola.filler

SRCS = main.c data.c play.c solve.c strarr.c pc.c ft_abs.c inttab.c

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
	
fun: re 
	@make -C libft clean
	@echo "Only binaries and .cs left"

fil: $(NAME)
	@$(GCC) $(SRCS) $(FLAGS) $(LIB) -o $(NAME)
