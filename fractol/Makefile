NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Ilibft/includes -I$(MLX_DIR) #-Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# --- Detect OS ---
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
	MLX_DIR = minilibx_opengl_20191021
	MLX_FLAGS = -framework OpenGL -framework AppKit
else
	MLX_DIR = minilibx-linux
	MLX_FLAGS = -lXext -lX11 -lm -lz
endif

MLX = $(MLX_DIR)/libmlx.a

SRCS = \
	fractol.c \
	color_manipulation.c

OBJS = $(SRCS:.c=.o)

# --- Build rules ---

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@$(MAKE) -C libft

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(MLX)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
