NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Ilibft/includes -I$(MLX_DIR) -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_FLAGS = -lXext -lX11 -lm -lz

MLX = $(MLX_DIR)/libmlx.a

SRCS = \
	fractol.c \
	trgb_util.c \
	pixel_utils.c \
	event_hooks.c \
	rendering.c \
	coordinate_mapping.c \
	usage.c \
	mouse_hooks.c \
	init_vars.c \
	clean_up.c \
	arg_parser.c \
	fractal_iterations.c

OBJS = $(SRCS:.c=.o)

# --- Rebuild .o if headers change ---
%.o: %.c fractol.h colors.h fractal_space.h keys.h
	$(CC) $(CFLAGS) -c $< -o $@

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
