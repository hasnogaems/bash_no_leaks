#include <stdio.h>
#include <stdlib.h>

#include "parse_flags.h"

int main(int argc, char *argv[]) {
  // printf("ARGC=%d", argc);
  FILE *fp;
  flags Flag;
  if (argc > 1) Flag = parse_flags(argc, argv);
  fp = fopen(argv[argc - 1], "r");
  int c;
  big_while(argc, fp, &Flag);
  if (argc == 1) argc1(&c);

  fclose(fp);
  return 0;
}
