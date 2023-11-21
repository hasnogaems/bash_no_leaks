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
  if (argc == 1)argc1(&c);
  
  fclose(fp);
  return 0;
}
