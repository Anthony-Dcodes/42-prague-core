NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_process_c.c ft_process_s.c ft_process_d.c \
	handle_sc_formats.c put_unsigned_int.c
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
