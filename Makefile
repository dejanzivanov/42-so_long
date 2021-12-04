# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 22:11:36 by dzivanov          #+#    #+#              #
#    Updated: 2021/11/06 18:11:24 by dzivanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

HEADER = so_long.h

SRCS	=	ft_itoa.c ft_game.c ft_utils1.c ft_rectangular_check.c ft_walls_checker.c \
			ft_utils2.c ft_utils3.c  ft_free_utils.c ft_read_utils.c \
			ft_player_movement.c ft_collectible_utils.c ft_image_utils.c \
			ft_image_utils1.c main.c

OBJS	=	${SRCS:.c=.o}

MLX		=	mlx
RM 		=	rm -rf

CC		=	gcc
CFLAGS	=	-g -Wall -Wextra -Werror
LDFLAGS =	-L${MLX} -lft

$(NAME):		mlx_all $(OBJS)
				$(CC) -o so_long $(CFLAGS) $(OBJS) mlx/libmlx_Linux.a -L/usr/include/X11/extensions -lX11 -lXext



all:		mlx_all ${NAME}

clean:
			${RM} ${OBJS}
			make -C ${MLX} clean

fclean:		clean
			${RM} ${NAME}
			make -C ${MLX} clean

re:			fclean all

mlx_all:
			cd mlx && ./configure

.PHONY:		all clean fclean re


#/*
#** gcc main.c game.c ft_utils1.c ft_utils2.c ft_utils3.c  ft_free_utils.c ft_read_utils.c ft_player_movement.c ft_collectible_utils.c ft_image_utils.c ft_image_utils1.c mlx/libmlx_Linux.a -L /usr/include/X11/extensions/ -lXext -lX11 && ./a.out maps/valid1.ber
#**
#*/