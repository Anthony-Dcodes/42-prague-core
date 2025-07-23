NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)  run_test

re: fclean all

run_test: $(NAME)
	$(CC) tests/tests.c $(NAME) -o run_test
	./run_test
