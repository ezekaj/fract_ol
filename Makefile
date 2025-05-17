NAME	:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42
LIBFT	:= ./libft
PRINTF	:= ./libft/printf
GNL		:= ./libft/gnl

HEADERS	:= -I ./inc -I $(LIBMLX)/include -I $(LIBFT) -I $(PRINTF) -I $(GNL)
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

LIBFT_SRCS := $(wildcard $(LIBFT)/*.c) $(wildcard $(PRINTF)/*.c) $(wildcard $(GNL)/*.c)
LIBFT_OBJS := $(LIBFT_SRCS:.c=.o)

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@echo "Compiling libft..."
	@make -C $(LIBFT)
	@echo "Compiling printf..."
	@make -C $(PRINTF)
	@echo "Compiling gnl..."
	@make -C $(GNL)
	@echo "Creating combined libft.a"
	@cp $(LIBFT)/libft.a $(LIBFT)/libft.a.bak
	@cp $(LIBFT)/libft.a ./
	@ar -x libft.a
	@ar -x $(PRINTF)/libftprintf.a
	@ar -x $(GNL)/libgnl.a
	@ar rcs $(LIBFT)/libft.a *.o
	@rm -f *.o
	@rm -f libft.a

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)
	@make -C $(LIBFT) clean
	@make -C $(PRINTF) clean
	@make -C $(GNL) clean
	@echo "Cleaning MLX42 build..."
	@rm -rf $(LIBMLX)/build

fclean: clean
	@echo "Cleaning executables and libraries..."
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(PRINTF) fclean
	@make -C $(GNL) fclean
	@rm -f $(LIBFT)/libft.a.bak

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft