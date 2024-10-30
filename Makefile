# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 20:10:55 by hmrabet           #+#    #+#              #
#    Updated: 2024/10/30 19:32:19 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

BONUS = cub3D_bonus

SRCS = 	mandatory/main.c \
 		mandatory/init-data.c \
		mandatory/utils/heap.c mandatory/utils/itoa.c mandatory/utils/split.c mandatory/utils/utils-0.c mandatory/utils/utils-1.c mandatory/utils/utils-2.c mandatory/utils/utils-3.c \
		mandatory/parser/parser.c mandatory/parser/parse-map.c mandatory/parser/parse-identifiers.c mandatory/parser/parser-utils.c \
		mandatory/mlx/launch_mlx.c \
		mandatory/tools/ft_get_color.c \
		mandatory/mlx/put_square.c \
		mandatory/mlx/put_circle.c \
		mandatory/mlx/put_line.c \
		mandatory/mlx/actions.c \
		mandatory/camera_moves/camera_moves.c \
		mandatory/mlx/put_line_v2.c \
		mandatory/tools/print_rays.c \
		mandatory/moves/move_f_b.c \
		mandatory/moves/move_l_r.c \
		mandatory/moves/move.c \
		mandatory/raycasting/cast_rays_h.c\
		mandatory/tools/raycast_utils.c \
		mandatory/raycasting/cast_rays_v.c

BSRCS = bonus/main_bonus.c \
 		bonus/init-data_bonus.c \
		bonus/utils/heap_bonus.c bonus/utils/itoa_bonus.c bonus/utils/split_bonus.c bonus/utils/utils-0_bonus.c bonus/utils/utils-1_bonus.c bonus/utils/utils-2_bonus.c bonus/utils/utils-3_bonus.c \
		bonus/parser/parser_bonus.c bonus/parser/parse-map_bonus.c bonus/parser/parse-identifiers_bonus.c bonus/parser/parser-utils_bonus.c \
		bonus/mlx/launch_mlx_bonus.c \
		bonus/tools/ft_get_color_bonus.c \
		bonus/mlx/put_square_bonus.c \
		bonus/mlx/put_circle_bonus.c \
		bonus/mlx/put_line_bonus.c \
		bonus/mlx/actions_bonus.c \
		bonus/camera_moves/camera_moves_bonus.c \
		bonus/mlx/put_line_v2_bonus.c \
		bonus/tools/print_rays_bonus.c \
		bonus/moves/move_f_b_bonus.c \
		bonus/moves/move_l_r_bonus.c \
		bonus/moves/move_bonus.c \
		bonus/raycasting/cast_rays_h_bonus.c\
		bonus/tools/raycast_utils_bonus.c \
		bonus/raycasting/cast_rays_v_bonus.c \
		bonus/tools/draw_bonus.c \
		bonus/tools/omen_bonus.c \
		bonus/tools/sounds_bonus.c \

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CC = cc #-Wall -Wextra -Werror  -g -fsanitize=address

INCLUDES = -IMLX42/include/MLX42  -Imandatory/includes
INCLUDES_B = -IMLX42/include/MLX42  -Ibonus/includes
MLX_FLAGS = -LMLX42/build -lmlx42 -ldl -lglfw -pthread -lm

all : mlx $(NAME)

bonus : mlx $(BONUS)

mlx :
	@if [ ! -d "MLX42" ]; then \
		echo "importing MLX42..."; \
		git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	@cd MLX42 && cmake -B build && cmake --build build -j4
	@echo "MLX42 is ready."

$(NAME):  $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(BONUS): $(BOBJS)
	$(CC) $(BOBJS) $(MLX_FLAGS) -o $(BONUS)

$(OBJS): %.o: %.c mandatory/includes/cub3d.h
	$(CC) $(INCLUDES) -c $< -o $@

$(BOBJS): %.o: %.c bonus/includes/cub3d_bonus.h
	$(CC) $(INCLUDES_B) -c $< -o $@

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME) $(BONUS)
	rm -rf MLX42

re : fclean all

.PHONY : clean fclean mlx
