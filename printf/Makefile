NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	handle_sc_formats.c common_print.c uiota.c \
	handle_diu_formats.c int_to_hex.c handle_xXp_formats.c
OBJ = $(SRC:.c=.o)

INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	$(CC) ft_printf_test.c $(NAME) libft.a -o runprog
	./runprog

.PHONY: all clean fclean re run
