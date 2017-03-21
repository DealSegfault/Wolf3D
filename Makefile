# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhalit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/27 22:03:25 by mhalit            #+#    #+#              #
#    Updated: 2017/02/25 19:16:46 by mhalit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = wolf.c hook.c map.c functions.c

OBJ = wolf.o hook.o map.o functions.o

LIBS = libft/libft.a

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):

#recompiler les new .c
	make -C ./libft
	make -C ./minilibx_macos
	gcc $(FLAGS) -c $(SRCS)
	#gcc $(FLAGS) $(OBJ) $(LIBS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	gcc $(FLAGS) $(OBJ) $(LIBS) -o $(NAME) -framework OpenGL -framework AppKit -I minilibx_macos ./minilibx_macos/libmlx.a
clean:
	rm -f $(OBJ)
	make -C ./libft clean
	make -C ./minilibx_macos clean
fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean
re: fclean all
