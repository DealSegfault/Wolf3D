# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhalit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/27 22:03:25 by mhalit            #+#    #+#              #
#    Updated: 2017/06/19 17:18:45 by mhalit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = wolf.c hook.c functions.c texture.c map2.c

OBJ = wolf.o hook.o functions.o texture.o map2.o

LIBS = libft/libft.a

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror -Ofast

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
