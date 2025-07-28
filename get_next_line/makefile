NAME = get_next_line.a
CC = cc
BUFFER_SIZE ?= 42
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)

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
	rm -f $(NAME)  run_tests

re: fclean all

run_tests: $(NAME)
	$(CC) tests/tests.c $(NAME) -o run_tests
	./run_tests

.PHONY: all clean fclea re run_tests
