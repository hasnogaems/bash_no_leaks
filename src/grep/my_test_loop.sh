#!/bin/bash

grep $@ test_e.txt > grep.txt
./s21_grep $@ test_e.txt > s21grep.txt
diff -s grep.txt s21grep.txt


