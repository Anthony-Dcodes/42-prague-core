NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft/includes

SRCS = \
	push_swap.c \
	ft_atoi_safe.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C libft
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

