# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/27 17:25:32 by mschmit           #+#    #+#              #
#    Updated: 2014/04/25 18:24:47 by mschmit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

INCDIR =	../includes

SOURCE = 	ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_itoa.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_puterr.c \
			ft_put.c \
			ft_sizei.c \
			ft_printf.c \
			ft_dprintf.c \
			ft_strdelc.c \
			get_next_line.c

OBJ =	$(SOURCE:.c=.o)

FLAG = -Wall -Wextra -Werror -g3

CC = gcc

all : $(NAME)

.PHONY: re fclean

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "[\033[33;32mCompilation \033[33;34m$(NAME) \
	\033[33;32mok\033[33;0m]"

%.o : %.c
	@$(CC) -c $(FLAG) $^ -I$(INCDIR)

clean :
	@rm -f $(OBJ)
	@echo "[\033[33;31mSupression des .o de \033[33;34m$(NAME) \
	\033[33;32mok\033[33;0m]"

fclean : clean
	@rm -f $(NAME)
	@echo "[\033[33;31mSupression de \033[33;34m$(NAME) \
	\033[33;32mok\033[33;0m]"

re : fclean all
