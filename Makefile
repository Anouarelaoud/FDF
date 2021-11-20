# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 17:30:07 by aait-el-          #+#    #+#              #
#    Updated: 2019/04/18 16:41:11 by aait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = *.c
INCLUDES = ./minilibx_macos
FLAGS= -Wall -Wextra -Werror
LIBRARIES = ./minilibx -lmlx -framework OpenGL -framework AppKit
LIBFT = ./libft/ -lft
all: $(NAME)

$(NAME):
	        @make -C libft
			        @gcc $(FLAGS) -o fdf $(SRCS) -I $(INCLUDES) -L $(LIBRARIES) -L $(LIBFT)

clean:
	        @make clean -C libft

fclean: clean
	        @make fclean -C libft
			        @rm -f $(NAME)

re: fclean all
