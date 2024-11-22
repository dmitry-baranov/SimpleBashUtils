CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

CAT_EXEC = s21_cat

CAT_SOURCE = s21_cat.c

all: clean s21_cat

s21_cat: $(CAT_EXEC)

$(CAT_EXEC): $(CAT_SOURCE)
	$(CC) $(CFLAGS) -o $@ $(CAT_SOURCE)

clang:
	find . -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -i --style=file:../../materials/linters/.clang-format {} +

test:
	sh cat_tests.sh

clean:
	rm -f $(CAT_EXEC)