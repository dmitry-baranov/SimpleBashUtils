# !/bin/bash

echo "./s21_cat text.txt"
./s21_cat text.txt > s21_cat.txt
cat text.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat text.txt text.txt"
./s21_cat text.txt text.txt > s21_cat.txt
cat text.txt text.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat -b text.txt"
./s21_cat -b text.txt > s21_cat.txt
cat -b text.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat -e text.txt"
./s21_cat -e text.txt > s21_cat.txt
cat -e text.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat -n text.txt"
./s21_cat -n text.txt > s21_cat.txt
cat -n text.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat -s text.txt"
./s21_cat -s text.txt > s21_cat.txt
cat -s text.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat -t text.txt"
./s21_cat -t text.txt > s21_cat.txt
cat -t text.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat -v text.txt"
./s21_cat -v text.txt > s21_cat.txt
cat -v text.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat --number-nonblank text.txt"
./s21_cat --number-nonblank text.txt > s21_cat.txt
cat -b text.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat --number text.txt"
./s21_cat --number text.txt > s21_cat.txt
cat -n text.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat --squeeze-blank text.txt"
./s21_cat --squeeze-blank text.txt > s21_cat.txt
cat -s text.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat text.txt text_nonprintable.txt"
./s21_cat text.txt text_nonprintable.txt > s21_cat.txt
cat text.txt text_nonprintable.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat text.txt text.txt"
./s21_cat text.txt text.txt > s21_cat.txt
cat text.txt text.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat -b text.txt text_nonprintable.txt"
./s21_cat -b text.txt text_nonprintable.txt > s21_cat.txt
cat -b text.txt text_nonprintable.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat -e text.txt text_nonprintable.txt"
./s21_cat -e text.txt text_nonprintable.txt > s21_cat.txt
cat -e text.txt text_nonprintable.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat -n text.txt text_nonprintable.txt"
./s21_cat -n text.txt text_nonprintable.txt > s21_cat.txt
cat -n text.txt text_nonprintable.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat -s text.txt text_nonprintable.txt"
./s21_cat -s text.txt text_nonprintable.txt > s21_cat.txt
cat -s text.txt text_nonprintable.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat -t text.txt text_nonprintable.txt"
./s21_cat -t text.txt text_nonprintable.txt > s21_cat.txt
cat -t text.txt text_nonprintable.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat -v text.txt text_nonprintable.txt"
./s21_cat -v text.txt text_nonprintable.txt > s21_cat.txt
cat -v text.txt text_nonprintable.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat --number-nonblank text.txt text_nonprintable.txt"
./s21_cat --number-nonblank text.txt text_nonprintable.txt > s21_cat.txt
cat -b text.txt text_nonprintable.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat --number text.txt text_nonprintable.txt"
./s21_cat --number text.txt text_nonprintable.txt > s21_cat.txt
cat -n text.txt text_nonprintable.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

echo "./s21_cat --squeeze-blank text.txt text_nonprintable.txt"
./s21_cat --squeeze-blank text.txt text_nonprintable.txt > s21_cat.txt
cat -s text.txt text_nonprintable.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt