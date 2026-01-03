# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/24 01:37:11 by megrelli          #+#    #+#              #
#    Updated: 2026/01/02 18:11:12 by megrelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra -Iinc -g

Libft = ./libft/libft.a

MLX = -Lmlx -lmlx -lXext -lX11 -lm -lbsd

SRCS = srcs_mandatory/main.c srcs_mandatory/init.c srcs_mandatory/textures.c \
srcs_mandatory/render.c srcs_mandatory/check_map.c srcs_mandatory/map.c \
srcs_mandatory/end_game.c srcs_mandatory/hooks.c srcs_mandatory/move.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(Libft):
	make -C ./libft

$(NAME): $(OBJS) $(Libft)
	cc $(OBJS) $(Libft) $(MLX) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all 

.PHONY: all clean fclean re


