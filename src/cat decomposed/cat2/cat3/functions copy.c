#include <stdio.h>
#include <stdlib.h>

#include "parse_flags.h"

void big_while(int argc, char **argv, FILE *fp, flags* Flag){
  int c;
  int count = 0;
  int line_count = 1;
  int new_line = 1;
  int current = 0;
  int previous = 10;
    while (1 && argc > 1) {
    c = fgetc(fp);
    current = c;
    if (feof(fp)) break;

if(v_and_s(&previous, &current, Flag, &c,  &count)){}
else{

    if (Flag->b == 0) {
      
      if (Flag->n == 1 && line_count == new_line) {  // flag n
        printf("%6.d\t", line_count);
        new_line = line_count + 1;
      }  // make it print line number only once for each new line
      if (Flag->n == 1 && current == 10) line_count++;
    }
    if (Flag->b == 1 && line_count == new_line && c != 10) {
      printf("%6.d\t", line_count);
      new_line = line_count + 1;
    }  //тут рассинхрон
    if (Flag->b == 1 && current == 10 && !(previous == 10 && current == 10))
      line_count++;  //как комментить сразу несколько строк
    previous = c;
    
    if (Flag->t == 1) {
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
    if (Flag->T == 1) {
      if (c == 9) {
        printf("^I");
        continue;
      }
      if (c == 27) continue;
    }

    printf("%c", c);
  }
    }
}

int v_and_s(int* previous, int* current, flags* Flag,int* c, int* count){
  int skip=0;
      if ((*previous) == 10 && (*current) == 10) {
      (*count)++;
    }

    if (Flag->v == 1 && Flag->e != 1) {
      if ((*c) < 32 && (*c) != 10 && (*c) != 9) {
        printf("^%c", (*c) + 64);
        skip=1;        
      }
      if ((*c) == 127) {
        skip=1;
        printf("^%c", (*c) - 128);
        
      }
    }

    if (Flag->s == 1 && (*previous) == 10 && (*current) == 10 && (*count) > 1) {  // flag
    
    skip=1;
                                                                        // s
    
    }
    if ((*current) != 10) {
      // if (extra_line == 1) {printf("\n");}
      (*count) = 0;
    }
  return skip;  
}
int flag_e(flags* Flag, int* c){
  if (Flag->e == 1 && Flag->E != 1) {
      if ((*c) < 32 && (*c) != 10 && (*c) != 9) {
        printf("^%c", (*c) + 64);

        continue=1
      }
      else if ((*c) == 127) {
        printf("^%c", (*c) - 128);
        continue=1
      }

      if ((*c) == 10) printf("$");
    }
}