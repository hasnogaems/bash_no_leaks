1:grep.c parse_flags.c regex.c
	gcc grep.c parse_flags.c regex.c -o s21_grep

2:prog4.c
	gcc prog4.c

flags:
	gcc -Wall -Werror -Wextra -std=c11 grep.c parse_flags.c regex.c

debug:
	gcc -fsanitize=address grep.c parse_flags.c regex.c	

test:
	./greybaca_grep_test_1.sh