#!/bin/bash

grep $@ test.txt > grep.txt
./s21_grep $@ test.txt > s21grep.txt
diff -s grep.txt s21grep.txt


