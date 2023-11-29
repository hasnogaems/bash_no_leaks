cppSHELL := /bin/bash
1: cat.c parse_flags.c functions.c
	gcc cat.c parse_flags.c functions.c -o s21_cat

2:cat.o parse_flags.o functions.o
	gcc cat.o parse_flags.o functions.o

cat.o: cat.c parse_flags.h
	gcc -c cat.c -o cat.o

parse_flags.o: parse_flags.c
	gcc -c parse_flags.c -o parse_flags.o

functions.o: functions.c
	gcc -c functions.c -o functions.o		

test:
	-diff <(./s21_cat -e sample.txt) <(cat -e sample.txt)
	-diff <(./s21_cat -v test.txt) <(cat -v test.txt)
	-diff <(./s21_cat -s test.txt) <(cat -s test.txt)
	-diff <(./s21_cat -n test.txt) <(cat -n test.txt)
	-diff <(./s21_cat -t test.txt) <(cat -t test.txt)
	-diff <(./s21_cat -b test.txt) <(cat -b test.txt)
	-diff <(./s21_cat -e test.txt) <(cat -e test.txt)
	-diff <(./s21_cat -v test.txt) <(cat -v test.txt)
	-diff <(./s21_cat -s test.txt) <(cat -s test.txt)
	-diff <(./s21_cat -n test.txt) <(cat -n test.txt)
	-diff <(./s21_cat -t test.txt) <(cat -t test.txt)
	-diff <(./s21_cat -b sample.txt) <(cat -b sample.txt)

test_linux:
	-diff <(./s21_cat -E test.txt) <(cat -E test.txt)
	-diff <(./s21_cat -T test.txt) <(cat -T test.txt)
	
	