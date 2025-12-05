NAME = client server

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft/includes

LIBFT = libft/libft.a

# Source files for each executable
CLIENT_SRCS = \
	client.c
SERVER_SRCS = \
	server.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C libft

client: $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o client

server: $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o server

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C libft
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	@$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all
