NAME	:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42
LIBFT	:= ./libft
PRINTF	:= ./libft/printf
GNL		:= ./libft/gnl

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT) -I $(PRINTF) -I $(GNL)
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

LIBFT_SRCS := $(wildcard $(LIBFT)/*.c) $(wildcard $(PRINTF)/*.c) $(wildcard $(GNL)/*.c)
LIBFT_OBJS := $(LIBFT_SRCS:.c=.o)

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft: $(LIBFT_OBJS)
	@echo "Creating libft.a"
	@ar rcs $(LIBFT)/libft.a $(LIBFT_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/libft.a

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft