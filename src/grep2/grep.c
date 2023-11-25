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
    //printf("Where?\n");
    Flags flag = parse_flags(argc, argv, e_ptrns, e_count);  // parse flags
    int y = parse_pattern(argc, argv, e_ptrns, &count);      // parse pattern
    int file_name = parse_file_name(y, argv, argc);          // parse file name

    printf("OPTIND=%d\n", optind);
    // printf("file name is %s its index is%d\n", argv[file_name], file_name);
//printf("line31\n");
    open_file_and_i_flag(&fp, &flag, optind, argv, &eflags);
    //printf("line33\n");
    char *line_ = (char *)malloc(1025 * sizeof(char));  // here we store line from our file we grabbed with fgets
    if(fp==NULL)printf("NULL fp\n");
    
  //printf("line34\n");
    //raw_pattern(flag, *line, *fp);
    if (flag.e != 1 && flag.v != 1 && flag.c !=1)
//printf("here?\n");
      while (fgets(line_, 1024, fp)) {
        
        x = regex(argv[y], line_, eflags);
        if (!x) printf("%s", line_);
      }
      
//printf("line 42\n");
    fseek(fp, 0, SEEK_SET);  // Move the cursor to the beginning of the file
    fgets(line_, 1024, fp);

    fseek(fp, 0, SEEK_SET);

    // exec e patterns
    if (flag.v == 1 && flag.e == 1) {
      while (fgets(line_, 1024, fp)) {  // print e patterns
        int loop_count = count;
        while (loop_count > 0) {  
          x = regex(e_ptrns[loop_count - 1], line_, eflags);
          loop_count--;
          // printf("X in E loop=%d\n", x);
          if (x) {
            printf("%s", line_);
          }
        }
      }
      printf("\n");
    }

    if (flag.v == 1) {
      // printf("V==1 and argv[y]=%s", argv[y]);
      while (fgets(line_, 1024, fp)) {  // print e patterns

        
        x = regex(argv[y], line_, eflags);

        // printf("X in E loop=%d\n", x);
        if (x) {
          printf("%s", line_);
        }
      }
      //printf("\n");
    }
    if (flag.v != 1 && flag.c != 1) {
      while (fgets(line_, 1024, fp)) {  // print e patterns
         int loop_count = count;
        while (loop_count > 0) { 
          x = regex(e_ptrns[loop_count - 1], line_, eflags);
          loop_count--;
          // printf("X in E loop=%d\n", x);
          if (!x) {
            printf("%s", line_);
          }
        }
      }
    }
    if (flag.c == 1&&flag.e==1) {
      int c_count = 0;
      while (fgets(line_, 1024, fp)) {  // print e patterns
        int loop_count = count;
        while (loop_count > 0) {  // что значат фиолетовые синие и желтые скобки
          x = regex(e_ptrns[loop_count - 1], line_, eflags);
          loop_count--;
          // printf("X in E loop=%d\n", x);
          if (!x) {
            c_count++;
          }
        }
      }
      printf("%d\n", c_count);
    }

    if(flag.c==1&&flag.e!=1){
      while (fgets(line_, 1024, fp)) {
        x = regex(argv[y], line_, eflags);
        if (!x) count++;
      }
      printf("%d\n", count);

    }
    //         printf("INSIDE THE e_ptrns:\n");
    // for(int n=0;n<2;n++){
    //     printf("%s\n", e_ptrns[n]);}

    free(pattern);
    free(line_);
    free(e_ptrns);
  }
  return 0;
}
