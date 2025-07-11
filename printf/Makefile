NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	handle_sc_formats.c common_print.c uiota.c \
	handle_diu_formats.c int_to_hex.c handle_xyp_formats.c \
	unsigned_long_to_hex.c
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
	rm -f $(NAME) runprog a.out

re: fclean all

run: $(NAME) libft.a
	$(CC) tests/ft_printf_test.c $(NAME) libft.a -o runprog
	./runprog


.PHONY: all clean fclean re run
