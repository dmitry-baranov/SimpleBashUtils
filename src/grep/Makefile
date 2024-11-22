CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

GREP_EXEC = s21_grep

GREP_SOURCE = s21_grep.c

all: clean s21_grep

s21_grep: $(GREP_EXEC)

$(GREP_EXEC): $(GREP_SOURCE)
	$(CC) $(CFLAGS) -o $@ $(GREP_SOURCE)

clang:
	find . -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -i --style=file:../../materials/linters/.clang-format {} +

test:
	sh grep_tests.sh

clean:
	rm -f $(GREP_EXEC)