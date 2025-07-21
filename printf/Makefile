NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./lib_ft

SRC = ft_printf.c \
	handle_sc_formats.c common_print.c uiota.c \
	handle_diu_formats.c int_to_hex.c handle_xxp_formats.c \
	unsigned_long_to_hex.c

OBJ = $(SRC:.c=.o)

LIBFT_SRC = $(LIBFT_DIR)/ft_calloc.c \
	$(LIBFT_DIR)/ft_itoa.c \
	$(LIBFT_DIR)/ft_strlen.c \
	$(LIBFT_DIR)/ft_putstr_fd.c \
	$(LIBFT_DIR)/ft_strchr.c \
	$(LIBFT_DIR)/ft_strdup.c \
	$(LIBFT_DIR)/ft_toupper.c \
	$(LIBFT_DIR)/ft_putchar_fd.c 


LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

ALL_OBJ = $(OBJ) $(LIBFT_OBJ)

INCLUDES = -I. -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(ALL_OBJ)
	ar rcs $(NAME) $(ALL_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME) runprog a.out run_ft run_std std_output.txt ft_output.txt

re: fclean all

run_ft: $(NAME)
	$(CC) tests/test_ft_printf.c $(NAME) -o run_ft
	./run_ft

run_std:
	$(CC) tests/test_standard_printf.c -o run_std
	./run_std

diff_outputs:
	@echo "Running tests..."
	@echo "Running ft_printf test..."
	-@make run_ft > ft_output.txt 2>&1
	@echo "Running standard printf test..."
	-@make run_std > std_output.txt 2>&1
	@echo "Comparing outputs..."
	@if cmp -s std_output.txt ft_output.txt; then \
		echo "✅ Outputs are identical!"; \
	else \
		echo "❌ Outputs differ:"; \
		echo "=========================================="; \
		if command -v diff >/dev/null 2>&1; then \
			diff -u std_output.txt ft_output.txt || true; \
		else \
			echo "diff not available, showing file contents:"; \
			echo "--- Standard printf ---"; \
			cat std_output.txt; \
			echo "--- Your ft_printf ---"; \
			cat ft_output.txt; \
		fi; \
		echo "=========================================="; \
		echo "Raw comparison (showing hidden chars):"; \
		echo "--- Standard printf ---"; \
		cat -A std_output.txt; \
		echo "--- Your ft_printf ---"; \
		cat -A ft_output.txt; \
	fi

clean_outputs:
	rm -f ft_output.txt std_output.txt


.PHONY: all clean fclean re run_ft run_std diff_outputs clean_outputs
