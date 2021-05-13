# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 04:16:15 by jleu              #+#    #+#              #
#    Updated: 2016/03/02 14:42:27 by jleu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/ft_atoi.c\
	  srcs/ft_realloc.c\
	  srcs/get_next_line.c\
	  srcs/ft_strtoupper.c\
	  srcs/ft_strrevchr.c\
	  srcs/ft_strtolower.c\
	  srcs/ft_strlonger.c\
	  srcs/ft_strclear.c\
	  srcs/ft_nbrlen.c\
	  srcs/ft_strrev.c\
	  srcs/ft_bzero.c\
	  srcs/ft_isalnum.c\
	  srcs/ft_isalpha.c\
	  srcs/ft_isascii.c\
	  srcs/ft_isdigit.c\
	  srcs/ft_isprint.c\
	  srcs/ft_itoa.c\
	  srcs/ft_lstadd.c\
	  srcs/ft_lstdel.c\
	  srcs/ft_lstdelone.c\
	  srcs/ft_lstiter.c\
	  srcs/ft_lstmap.c\
	  srcs/ft_lstnew.c\
	  srcs/ft_memalloc.c\
	  srcs/ft_memcpy.c\
	  srcs/ft_memccpy.c\
	  srcs/ft_memchr.c\
	  srcs/ft_memcmp.c\
	  srcs/ft_memdel.c\
	  srcs/ft_memmove.c\
	  srcs/ft_memset.c\
	  srcs/ft_putchar.c\
	  srcs/ft_putchar_fd.c\
	  srcs/ft_putendl.c\
	  srcs/ft_putendl_fd.c\
	  srcs/ft_putnbr.c\
	  srcs/ft_putnbr_fd.c\
	  srcs/ft_putstr.c\
	  srcs/ft_putstr_fd.c\
	  srcs/ft_strcat.c\
	  srcs/ft_strchr.c\
	  srcs/ft_strclr.c\
	  srcs/ft_strcmp.c\
	  srcs/ft_strcpy.c\
	  srcs/ft_strdel.c\
	  srcs/ft_strdup.c\
	  srcs/ft_strequ.c\
	  srcs/ft_striter.c\
	  srcs/ft_striteri.c\
	  srcs/ft_strjoin.c\
	  srcs/ft_strlcat.c\
	  srcs/ft_strlen.c\
	  srcs/ft_strmap.c\
	  srcs/ft_strmapi.c\
	  srcs/ft_strncat.c\
	  srcs/ft_strncmp.c\
	  srcs/ft_strncpy.c\
	  srcs/ft_strnequ.c\
	  srcs/ft_strnew.c\
	  srcs/ft_strnstr.c\
	  srcs/ft_strrchr.c\
	  srcs/ft_strsplit.c\
	  srcs/ft_strstr.c\
	  srcs/ft_strsub.c\
	  srcs/ft_strtrim.c\
	  srcs/ft_tolower.c\
	  srcs/ft_toupper.c

OBJ = ft_atoi.o\
	  ft_realloc.o\
	  ft_strtoupper.o\
	  ft_strrevchr.o\
	  ft_strtolower.o\
	  ft_strlonger.o\
	  ft_strclear.o\
	  ft_nbrlen.o\
	  ft_strrev.o\
	  ft_bzero.o\
	  ft_isalnum.o\
	  ft_isalpha.o\
	  ft_isascii.o\
	  ft_isdigit.o\
	  ft_isprint.o\
	  ft_itoa.o\
	  ft_lstadd.o\
	  ft_lstdel.o\
	  ft_lstdelone.o\
	  ft_lstiter.o\
	  ft_lstmap.o\
	  ft_lstnew.o\
	  ft_memalloc.o\
	  ft_memcpy.o\
	  ft_memccpy.o\
	  ft_memchr.o\
	  ft_memcmp.o\
	  ft_memdel.o\
	  ft_memmove.o\
	  ft_memset.o\
	  ft_putchar.o\
	  ft_putchar_fd.o\
	  ft_putendl.o\
	  ft_putendl_fd.o\
	  ft_putnbr.o\
	  ft_putnbr_fd.o\
	  ft_putstr.o\
	  ft_putstr_fd.o\
	  ft_strcat.o\
	  ft_strchr.o\
	  ft_strclr.o\
	  ft_strcmp.o\
	  ft_strcpy.o\
	  ft_strdel.o\
	  ft_strdup.o\
	  ft_strequ.o\
	  ft_striter.o\
	  ft_striteri.o\
	  ft_strjoin.o\
	  ft_strlcat.o\
	  ft_strlen.o\
	  ft_strmap.o\
	  ft_strmapi.o\
	  ft_strncat.o\
	  ft_strncmp.o\
	  ft_strncpy.o\
	  ft_strnequ.o\
	  ft_strnew.o\
	  ft_strnstr.o\
	  ft_strrchr.o\
	  ft_strsplit.o\
	  ft_strstr.o\
	  ft_strsub.o\
	  ft_strtrim.o\
	  ft_tolower.o\
	  ft_toupper.o\
	  get_next_line.o

FLAGS = -Wall \
		-Wextra \
		-Werror

NAME = libft.a

INCPATH = ./includes

all: $(NAME)

$(OBJ):
	gcc $(FLAGS) -c $(SRC) -I$(INCPATH)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : re clean fclean all
