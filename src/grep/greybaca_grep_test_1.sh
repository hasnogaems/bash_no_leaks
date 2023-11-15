#!/bin/bash
diff -s <(grep $1 $2 11 test_e.txt) <(./s21_grep $1 $2 11 test_e.txt)

