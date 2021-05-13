# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 23:53:34 by jleu              #+#    #+#              #
#    Updated: 2016/03/18 01:02:59 by jleu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/fdf.c					\
	  srcs/ft_get_points.c			\
	  srcs/ft_projection.c			\
	  srcs/ft_putline.c				\
	  srcs/ft_get_min_max.c			\
	  srcs/ft_images.c				\
	  srcs/ft_put_pixel_to_image.c	\
	  srcs/ft_resize.c				\
	  srcs/ft_quit.c				\

OBJ = fdf.o							\
	  ft_get_points.o				\
	  ft_projection.o				\
	  ft_putline.o					\
	  ft_get_min_max.o				\
	  ft_images.o					\
	  ft_put_pixel_to_image.o		\
	  ft_resize.o					\
	  ft_quit.o						\

NAME = fdf

INCPATH = ./includes

FLAGS = -Wall						\
		-Wextra						\
		-Werror						\

LIBS = libft/libft.a				\
	   -lmlx						\
	   -framework OpenGL			\
	   -framework Appkit			\

all: $(NAME)

$(OBJ):
	cd libft/ && $(MAKE)
	cd ../
	gcc $(FLAGS) -c $(SRC) -I$(INCPATH)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBS) -I$(INCPATH)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : re clean fclean all
