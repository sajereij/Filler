# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 11:48:42 by sreijola          #+#    #+#              #
#    Updated: 2020/09/28 01:15:09 by sreijola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

SRCS = ft_atoi.c\
	ft_itoa.c\
	ft_intlen.c\
	ft_ulltoa_base.c\
	ft_ulllen.c\
	ft_lltoa.c\
	ft_lllen.c\
	ft_bigintlen.c\
	ft_strround_up.c\
	ft_bzero.c\
	ft_memalloc.c\
	ft_memchr.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memcmp.c\
	ft_memdel.c\
	ft_memmove.c\
	ft_memset.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_islower.c\
	ft_isupper.c\
	ft_isblank.c\
	ft_putnbr.c\
	ft_putnbr_fd.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_putstr_ret_fd.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strjoin.c\
	ft_strjoin_free.c\
	ft_strsplit.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strlcat.c\
	ft_strncat.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_strclr.c \
	ft_strdel.c \
	ft_strchr.c \
	ft_strrchr.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_strrev.c\
	ft_strlen.c\
	ft_strnew.c\
	ft_strdup.c\
	ft_strdup_free.c\
	ft_strndup_free.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_count_words.c\
	ft_swap.c\
	ft_pow.c\
	get_next_line.c

FT_PRINTF_C = ft_printf.c ft_printf_fill_struct.c ft_printf_parse.c\
	ft_printf_type_diouxxf.c ft_printf_type_csp.c ft_printf_adapter.c\
	ft_printf_adapter_preciser.c ft_printf_adapter_signer.c ft_printf_bonus.c\
	ft_printf_edgecases.c ft_printf_ldtoa.c ft_printf_putfstr_fd.c

FT_PRINTF_PATH = ./ft_printf/

FT_PRINTF_SRCS = $(addprefix $(FT_PRINTF_PATH), $(FT_PRINTF_C))

OBJS = $(patsubst %.c, %.o, $(SRCS) $(FT_PRINTF_C))

INCL = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(SRCS) $(FT_PRINTF_SRCS) -c $(FLAGS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Libft made"

clean: 
	rm -f $(OBJS)
	@echo "Object files removed from libft. Beep-Bop"

fclean: clean
	rm -f $(NAME)
	@echo "Binaries and object files gone."
	
re: fclean all
	@echo "All good again"
