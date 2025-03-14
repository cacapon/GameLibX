# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 12:57:47 by ttsubo            #+#    #+#              #
#    Updated: 2025/03/12 13:06:26 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 全部をまとめたlibglx.aがほしい
NAME	= libglx.a
CC		= cc

W_FLG	= -Wall -Wextra -Werror
I_FLG	= -Iinc -Ilib/mlx -Ilib/libft
L_FLG	= -Llib/mlx -lmlx -lX11 -lXext 

GLX_DIR = src/
BLD_DIR = bld/

LFT_DIR = lib/libft/
MLX_DIR = lib/mlx/

SRC = glx.c

SRCS = $(addprefix $(GLX_DIR), $(SRC))
OBJS = $(addprefix $(BLD_DIR), $(SRC:.c=.o))

ifeq ($(MAKECMDGOALS), debug)
CC := cc -g
DEBUG = debug
endif

all: $(NAME)
debug: $(NAME)

$(NAME): $(LFT_DIR)libft.a $(MLX_DIR)libmlx_Linux.a $(OBJS)
	cd $(BLD_DIR) && ar x ../$(LFT_DIR)libft.a
	cd $(BLD_DIR) && ar x ../$(MLX_DIR)libmlx_Linux.a
	ar rcs $(NAME) $(BLD_DIR)*.o

$(BLD_DIR)%.o: $(GLX_DIR)%.c
	$(CC) $(W_FLG) -c $< -o $@ $(I_FLG)

$(LFT_DIR)libft.a: $(LFT_DIR)libft.h
	$(MAKE) -C $(LFT_DIR) $(DEBUG)

$(MLX_DIR)libmlx_Linux.a: $(MLX_DIR)mlx.h
	$(MAKE) -C $(MLX_DIR)

$(LFT_DIR)libft.h:
	git submodule update -i --recursive

$(MLX_DIR)mlx.h:
	git submodule update -i --recursive

clean:
	$(MAKE) -C $(LFT_DIR) clean
	rm -f $(BLD_DIR)*.o

fclean: clean
	$(MAKE) -C $(LFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug