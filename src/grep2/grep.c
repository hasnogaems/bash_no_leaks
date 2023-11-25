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
    int count = 0;
    int *e_count = &count;
    FILE *fp;
    int eflags = 0;
    char *pattern = malloc(100 * sizeof(char));
    char **e_ptrns = (char **)malloc(1025 * sizeof(char *));
    int c=0;
    int x;
    printf("Where?\n");
    Flags flag = parse_flags(argc, argv, e_ptrns, e_count);  // parse flags
    int y = parse_pattern(argc, argv, e_ptrns, &count);      // parse pattern
    int file_name = parse_file_name(y, argv, argc);          // parse file name

    //printf("OPTIND=%d\n", optind);
    // printf("file name is %s its index is%d\n", argv[file_name], file_name);
printf("line31\n");
    open_file_and_i_flag(&fp, &flag, optind, argv, &eflags);
    
    //printf("line33\n");
if(fp==NULL)printf("NULL fp in MAIN func\n");
    char *line_ = (char *)malloc(1025 * sizeof(char));  // here we store line from our file we grabbed with fgets
    printf("line 36\n");
    grep(flag, fp, eflags, line_, argv, y, count, e_ptrns);
    if(fp==NULL)printf("NULL fp\n");
    
  printf("line34\n");
    //raw_pattern(flag, *line, *fp);
   
    free(pattern);
    free(line_);
    free(e_ptrns);
  }
  return 0;
}
