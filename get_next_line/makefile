NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wetra -Werror -D BUFFER_SIZE=42

SRC = get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) runprog a.out run_ft run_std std_output.txt ft_output.txt

re: fclean all
