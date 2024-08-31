# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 20:10:55 by hmrabet           #+#    #+#              #
#    Updated: 2024/08/31 16:58:18 by mel-hamd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

BONUS = cub3D_bonus

SRCS = 	main.c \
 		init-data.c \
		utils/heap.c \
		utils/itoa.c \
		utils/split.c \
		utils/utils-0.c \
		utils/utils-1.c \
		utils/utils-2.c \
		parser/parser.c \
		mlx/lunch_mlx.c

#BSRCS = 

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CC = cc -Wall -Wextra -Werror

# HDR = mlx42/libmlx.a
INCLUDES = -Imlx42  -Iincludes 
MLX_FLAGS = -Lmlx42 -lmlx -framework Cocoa -framework OpenGL -framework IOKit

all : $(NAME)

bonus : $(BONUS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) $(HDR) -o $(NAME)

$(BONUS): $(BOBJS)
	$(CC) $(BOBJS) $(MLX_FLAGS) -o $(BONUS)

%.o: %.c includes/cub3d.h
	$(CC) $(INCLUDES) -c $< -o $@

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : clean fclean
