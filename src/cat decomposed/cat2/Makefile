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