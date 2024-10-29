#!/bin/bash

# Create the Makefile with the desired content
cat << 'EOF' > Makefile
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 20:10:55 by hmrabet           #+#    #+#              #
#    Updated: 2024/10/15 21:57:11 by hmrabet          ###   ########.fr        #
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

CC = cc #-Wall -Wextra -Werror  -g -fsanitize=address

INCLUDES = -IMLX42/include/MLX42  -Iincludes 
MLX_FLAGS = -LMLX42/build -lmlx42 -ldl -lglfw -pthread -lm

all : mlx $(NAME)

bonus : $(BONUS)

mlx :
	cd MLX42 && cmake -B build && cmake --build build -j4

$(NAME):  $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

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
EOF

echo "Makefile has been created successfully for MAC OS."
