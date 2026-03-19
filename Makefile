# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 15:30:00 by ezekaj            #+#    #+#              #
#    Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fractol
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

MLX_DIR		:= ./minilibx-linux
MLX			:= $(MLX_DIR)/libmlx.a
LIBFT_DIR	:= ./libft
LIBFT		:= $(LIBFT_DIR)/libft.a
PRINTF_DIR	:= $(LIBFT_DIR)/printf
GNL_DIR		:= $(LIBFT_DIR)/gnl

HEADERS		:= -I ./inc -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(GNL_DIR)
MLX_FLAGS	:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS		:= src/main.c src/parse.c src/init.c \
			   src/fractal.c src/render.c src/events.c
OBJS		:= $(SRCS:.c=.o)

SRCS_B		:= src/main_bonus.c src/parse_bonus.c src/init_bonus.c \
			   src/fractal_bonus.c src/render_bonus.c \
			   src/colors_bonus.c src/colors_util_bonus.c \
			   src/events_bonus.c src/events_util_bonus.c
OBJS_B		:= $(SRCS_B:.c=.o)

all: $(NAME)

$(MLX):
	@make -C $(MLX_DIR) > /dev/null 2>&1

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@make -C $(GNL_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT_DIR)/libft.a.bak 2>/dev/null || true
	@ar -x $(PRINTF_DIR)/libftprintf.a 2>/dev/null || true
	@ar -x $(GNL_DIR)/libgnl.a 2>/dev/null || true
	@ar rcs $(LIBFT_DIR)/libft.a *.o 2>/dev/null || true
	@rm -f *.o

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

bonus: $(MLX) $(LIBFT) $(OBJS_B)
	@$(CC) $(OBJS_B) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_B)
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@make -C $(PRINTF_DIR) clean > /dev/null 2>&1
	@make -C $(GNL_DIR) clean > /dev/null 2>&1
	@make -C $(MLX_DIR) clean > /dev/null 2>&1

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@make -C $(PRINTF_DIR) fclean > /dev/null 2>&1
	@make -C $(GNL_DIR) fclean > /dev/null 2>&1
	@rm -f $(LIBFT_DIR)/libft.a.bak

re: fclean all

.PHONY: all clean fclean re bonus
