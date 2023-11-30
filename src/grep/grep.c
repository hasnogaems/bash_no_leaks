#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#include "h.h"
#define no_argument 0
#define required_argument 1
#define optional_argument 2
int main(int argc, char *argv[]) {
  if (argc == 1)
    printf(
        "Usage: grep [OPTION]... PATTERNS [FILE]...\nTry 'grep --help' for "
        "more information.\n");
  else {
    FILE *fp;
    int eflags = 0;
    char *line_ = (char *)malloc(1025 * sizeof(char));
    // printf("Where?\n");
    Flags flag = parse_flags(argc, argv);      // parse flags
    int y = parse_pattern(argc, argv);        // parse pattern
    while (optind < argc) {
      if (open_file_and_i_flag(&fp, &flag, argv, &eflags) == 0) {
        // printf("OPTIND=%d", optind);
        optind++;
        continue;
      }

      // printf("line33\n");
      // if(fp==NULL)printf("NULL fp in MAIN func\n");
      //  here we store line from our file we grabbed with fgets
      // printf("line 36\n");
      grep(flag, fp, line_, argv, y);
      // if(fp==NULL)printf("NULL fp\n");

      // printf("line34\n");
      // raw_pattern(flag, *line, *fp);

      optind++;
    }
    // free(pattern);
    // free(e_ptrns);
    // fclose(fp);
    free(line_);
  }
  return 0;
}
