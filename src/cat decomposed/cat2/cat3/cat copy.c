#include <stdio.h>
#include <stdlib.h>

#include "parse_flags.h"

int main(int argc, char *argv[]) {
  // printf("ARGC=%d", argc);
  FILE *fp;
  int line_index = 0;
  int s;
  flags Flag;
  if (argc > 1) Flag = parse_flags(argc, argv);
  fp = fopen(argv[argc - 1], "r");
  int c;
  big_while(argc, argv, fp, &Flag);
  if (argc == 1) {
    char *noargs;
    int counter = 1;
    noargs = malloc(counter * sizeof(char));
    while (1) {
      if (counter > 1) noargs = realloc(noargs, counter * sizeof(char));

      c = getchar();

      if (c == EOF) { /*printf("\n")*/
        break;
      }
      if (c != 10) noargs[counter - 1] = c;
      if (c == 10)
        while (counter > 0) {
          printf("%c", noargs[counter - 1]);
          counter--;
        }
      if (counter == 0) printf("\n");
      counter++;
    }
    free(noargs);
  }

  fclose(fp);
  return 0;
}
