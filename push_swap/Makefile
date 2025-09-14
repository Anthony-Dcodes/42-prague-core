NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft/includes

SRCS = \
	push_swap.c \
	node_functions.c \
	utils.c \
	init_stack_a.c \
	stack_ops_sa_sb_ss.c \
	stack_ops_pa_pb.c \
	stack_ops_ra_rb_rr.c \
	stack_ops_rra_rrb_rrr.c

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

