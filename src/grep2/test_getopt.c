#include <getopt.h>
#include <stdio.h>
int main(int argc, char **argv) {
  getopt(argc, argv, "+etb");
  printf("%d\n", optind);
  for (int i = 0; i < 3; i++) printf("%s ", argv[i]);
  return 0;
}