# !/bin/bash

echo "TEST ./s21_grep the text.txt text1.txt > s21_grep.txt"
./s21_grep the text.txt text1.txt > s21_grep.txt
grep the text.txt text1.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo "TEST ./s21_grep -e the -e if text.txt > s21_grep.txt"
./s21_grep -e the -e if text.txt > s21_grep.txt
grep -e the -e if text.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo "TEST ./s21_grep -i the text.txt > s21_grep.txt"
./s21_grep -i the text.txt > s21_grep.txt
grep -i the text.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo "TEST ./s21_grep -v s text.txt > s21_grep.txt"
./s21_grep -v s text.txt > s21_grep.txt
grep -v s text.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo "TEST ./s21_grep -c s text.txt > s21_grep.txt"
./s21_grep -c s text.txt > s21_grep.txt
grep -c s text.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo "TEST ./s21_grep -l s text.txt text1.txt text_nonprintable.txt > s21_grep.txt"
./s21_grep -l s text.txt text1.txt text_nonprintable.txt > s21_grep.txt
grep -l s text.txt text1.txt text_nonprintable.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo "TEST ./s21_grep -n s text.txt > s21_grep.txt"
./s21_grep -n s text.txt > s21_grep.txt
grep -n s text.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo "TEST ./s21_grep -in the text.txt > s21_grep.txt"
./s21_grep -in the text.txt > s21_grep.txt
grep -in the text.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo "TEST ./s21_grep -cv s text.txt > s21_grep.txt"
./s21_grep -cv s text.txt > s21_grep.txt
grep -cv s text.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo "TEST ./s21_grep -iv s text.txt > s21_grep.txt"
./s21_grep -iv s text.txt > s21_grep.txt
grep -iv s text.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo "TEST ./s21_grep -lv s text.txt text1.txt text_nonprintable.txt > s21_grep.txt"
./s21_grep -lv s text.txt text1.txt text_nonprintable.txt > s21_grep.txt
grep -lv s text.txt text1.txt text_nonprintable.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt