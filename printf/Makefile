NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_printf.c \
	handle_sc_formats.c common_print.c uiota.c \
	handle_diu_formats.c int_to_hex.c handle_xxp_formats.c \
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

run_ft: $(NAME) libft.a
	$(CC) tests/test_ft_printf.c $(NAME) libft.a -o run_ft
	./run_ft

run_std:
	$(CC) tests/test_standard_printf.c -o run_std
	./run_std

diff_outputs:
	make run_ft > ft_output.txt
	make run_std > std_output.txt
	diff -u std_output.txt ft_output.txt


.PHONY: all clean fclean re run run_ft run_std diff_outputs
