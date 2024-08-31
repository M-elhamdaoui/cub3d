# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 20:10:55 by hmrabet           #+#    #+#              #
#    Updated: 2024/08/31 15:10:11 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

BONUS = cub3D_bonus

SRCS = main.c init-data.c utils/heap.c utils/itoa.c utils/split.c utils/utils-0.c utils/utils-1.c utils/utils-2.c parser/parser.c

#BSRCS = 

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CC = cc -Wall -Wextra -Werror

INCLUDES = -Imlx42 -Ilibft
MLX_FLAGS = -lmlx -Lmlx42 -framework Cocoa -framework OpenGL -framework IOKit

all : $(NAME)

bonus : $(BONUS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(BONUS): $(BOBJS)
	$(CC) $(BOBJS) $(MLX_FLAGS) -o $(BONUS)

%.o: %.c includes/cub3d.h
	$(CC) ${INCLUDES} -c $< -o $@

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : clean fclean
