#include <stdio.h>
#include <stdlib.h>

#include "parse_flags.h"
int extralines(FILE *fp) {
  int c;
  int enter = 0;
  int empty = 0;
  int previous;
  int number_of_enters = 0;

  while (1) {
    c = fgetc(fp);
    if (feof(fp)) break;
    printf("%c", c);

    if (previous == 10 && c == 10) empty++;

    previous = c;
  }

  printf("number of empty lines=%d\n", empty);
  return empty;
}
int big_while(int argc, char **argv){
    while (1 && argc > 1) {
    c = fgetc(fp);
    current = c;
    if (feof(fp)) break;

    if (previous == 10 && current == 10) {
      count++;
    }

    if (Flag.v == 1 && Flag.e != 1) {
      if (c < 32 && c != 10 && c != 9) {
        printf("^%c", c + 64);

        continue;
      }
      if (c == 127) {
        printf("^%c", c - 128);
        continue;
      }
    }
    if (Flag.s == 1 && previous == 10 && current == 10 && count > 1) {  // flag
                                                                        // s
      continue;
    }
    if (current != 10) {
      // if (extra_line == 1) {printf("\n");}
      count = 0;
    }

    if (Flag.b == 0) {
      if (Flag.n == 1 && line_count == new_line) {  // flag n
        printf("%6.d\t", line_count);
        new_line = line_count + 1;
      }  // make it print line number only once for each new line
      if (Flag.n == 1 && current == 10) line_count++;
    }
    if (Flag.b == 1 && line_count == new_line && c != 10) {
      printf("%6.d\t", line_count);
      new_line = line_count + 1;
    }  //тут рассинхрон
    if (Flag.b == 1 && current == 10 && !(previous == 10 && current == 10))
      line_count++;  //как комментить сразу несколько строк
    previous = c;
    if (Flag.e == 1 && Flag.E != 1) {
      if (c < 32 && c != 10 && c != 9) {
        printf("^%c", c + 64);

        continue;
      }
      if (c == 127) {
        printf("^%c", c - 128);
        continue;
      }

      if (c == 10) printf("$");
    }
    if (Flag.t == 1) {
      if (c < 32 && c != 10 && c != 9) {
        printf("^%c", c + 64);
        continue;
      }
      if (c == 127) {
        printf("^%c", c - 128);
        continue;
      }
      if (c == 9) {
        printf("^I");
        continue;
      }
    }
    if (Flag.T == 1) {
      if (c == 9) {
        printf("^I");
        continue;
      }
      if (c == 27) continue;
    }

    printf("%c", c);
  }
}