NAME = get_next_line.a
CC = cc
BUFFER_SIZE ?= 42
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

# Test files to create
TEST_FILES = tests/test_empty.txt tests/test_short_lines.txt tests/test_long_lines.txt tests/code_text.txt

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create test directory and files
tests/test_empty.txt:
	@mkdir -p tests
	@touch tests/test_empty.txt

tests/test_short_lines.txt:
	@mkdir -p tests
	@echo "Line 1" > tests/test_short_lines.txt
	@echo "Line 2" >> tests/test_short_lines.txt
	@echo "Line 3" >> tests/test_short_lines.txt
	@echo "Last line without newline" | tr -d '\n' >> tests/test_short_lines.txt

tests/test_long_lines.txt:
	@mkdir -p tests
	@echo "This is a very long line that should test how get_next_line handles lines longer than the buffer size. It contains many characters and should be properly read even if BUFFER_SIZE is small." > tests/test_long_lines.txt
	@echo "Another long line with different content to ensure multiple long lines work correctly. This line also has many characters to test the buffer handling thoroughly." >> tests/test_long_lines.txt
	@echo "Short line" >> tests/test_long_lines.txt
	@printf "Final long line without newline: Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua." >> tests/test_long_lines.txt

tests/code_text.txt:
	@mkdir -p tests
	@echo "#include <stdio.h>" > tests/code_text.txt
	@echo "" >> tests/code_text.txt
	@echo "int main(void)" >> tests/code_text.txt
	@echo "{" >> tests/code_text.txt
	@echo "    printf(\"Hello, World!\\\n\");" >> tests/code_text.txt
	@echo "    return (0);" >> tests/code_text.txt
	@echo "}" >> tests/code_text.txt

# Build test executable
run_tests: $(NAME) $(TEST_FILES)
	$(CC) $(CFLAGS) tests/tests.c $(NAME) -o run_tests
	./run_tests

# Test with different buffer sizes
test-buffer-sizes: $(TEST_FILES)
	@echo "Testing with BUFFER_SIZE=1"
	@$(MAKE) fclean && $(MAKE) BUFFER_SIZE=1 run_tests
	@echo "\nTesting with BUFFER_SIZE=10"
	@$(MAKE) fclean && $(MAKE) BUFFER_SIZE=10 run_tests
	@echo "\nTesting with BUFFER_SIZE=42"
	@$(MAKE) fclean && $(MAKE) BUFFER_SIZE=42 run_tests
	@echo "\nTesting with BUFFER_SIZE=1000"
	@$(MAKE) fclean && $(MAKE) BUFFER_SIZE=1000 run_tests
	@echo "\nTesting with BUFFER_SIZE=9999"
	@$(MAKE) fclean && $(MAKE) BUFFER_SIZE=9999 run_tests

# Quick test with current buffer size
test: run_tests

# Memory leak test with valgrind (if available)
valgrind-test: run_tests
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "Running valgrind memory leak test..."; \
		echo "test line 1" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./run_tests; \
	else \
		echo "Valgrind not found. Install valgrind for memory leak testing."; \
	fi

# Create additional test files for edge cases
create-edge-case-tests:
	@mkdir -p tests
	@echo "Creating edge case test files..."
	@printf "No newline at end" > tests/test_no_newline.txt
	@printf "\n\n\n" > tests/test_only_newlines.txt
	@printf "" > tests/test_empty.txt
	@python3 -c "print('x' * 10000)" > tests/test_very_long_line.txt
	@echo "Edge case test files created!"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) run_tests
	rm -rf tests/

re: fclean all

.PHONY: all clean fclean re run_tests test test-buffer-sizes valgrind-test create-edge-case-tests