#!/bin/bash

grep $@ test_e.txt test.txt > grep.txt
./s21_grep $@ test_e.txt test.txt > s21grep.txt
diff -s grep.txt s21grep.txt

grep $@ lyrics1.txt lyrics1.txt > grep.txt
./s21_grep $@ lyrics1.txt lyrics1.txt > s21grep.txt
diff -s grep.txt s21grep.txt


