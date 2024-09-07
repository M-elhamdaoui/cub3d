# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 20:10:55 by hmrabet           #+#    #+#              #
#    Updated: 2024/09/07 19:17:33 by mel-hamd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

BONUS = cub3D_bonus

SRCS = 	main.c \
 		init-data.c \
		utils/heap.c utils/itoa.c utils/split.c utils/utils-0.c utils/utils-1.c utils/utils-2.c utils/utils-3.c \
		parser/parser.c parser/parse-map.c parser/parse-identifiers.c parser/parser-utils.c \
		mlx/launch_mlx.c \
		tools/ft_get_color.c \
		mlx/put_square.c \
		mlx/put_circle.c \
		mlx/put_line.c \
		mlx/actions.c \
		camera_moves/camera_moves.c \
		mlx/put_line_v2.c \
		tools/print_rays.c \
		moves/move_f_b.c \
		moves/move_l_r.c \
		moves/move.c \
		raycasting/cast_rays_h.c\
		tools/raycast_utils.c \
		raycasting/cast_rays_v.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CC = cc -Wall -Wextra -Werror  -fsanitize=address

LIB = -L"/Users/${USER}/.brew/Cellar/glfw/3.4/lib/"

HDR = MLX42/build/libmlx42.a
INCLUDES = -IMLX42/include/MLX42  -Iincludes 
MLX_FLAGS = -LMLX42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw

all : mlx $(NAME)

bonus : $(BONUS)

mlx :
	cd MLX42 && cmake -B build && cmake --build build -j4

$(NAME):  $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) $(HDR) ${LIB} -o $(NAME)

$(BONUS): $(BOBJS)
	$(CC) $(BOBJS) $(MLX_FLAGS) -o $(BONUS)

%.o: %.c includes/cub3d.h
	$(CC) $(INCLUDES) -c $< -o $@

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME) $(BONUS)
	cd MLX42 && rm -rf build

re : fclean all

.PHONY : clean fclean mlx
