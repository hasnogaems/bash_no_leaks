#include "h.h"
void add_pattern(char* pattern, Flags* flag) {
  if (strlen(flag->pattern) > 0) strcat(flag->pattern, "|");
  strcat(flag->pattern, pattern);
}

int open_file_and_i_flag(FILE** fp, Flags* flag, int file_name, char** argv,
                         int* eflags) {
  int result = 0;
  // printf("in open_file argv[%d]=%s\n", optind, argv[optind]);
  (*fp) = fopen(argv[optind], "r");  // opening file
  if ((*fp) == NULL) {
    // printf("Error opening file.\n");
    return 0;  // debug
  }
  // here we store line from our file we grabbed with fgets
  if (flag->i == 1) {  // no distinction between upper and lowercase characters
    (*eflags) = REG_ICASE;
    // printf("EFLAGS IN MAIN=%d\n", eflags);
  }
  return 1;
}
/* grep_file(){

} */

void pattern_from_file(char* line_, Flags* flag) {
  FILE* pt = NULL;
  pt = fopen(optarg, "r");
  if (pt == NULL)
    printf("in function pattern_file file is not read! optarg=%s", optarg);
  if (pt != NULL) {
    // char string[1024];
    while (fgets(line_, 1024, pt) != NULL) {
      if (line_[strlen(line_) - 1] == '\n') line_[strlen(line_) - 1] = '\0';

      add_pattern(line_, flag);
    }
  } else {
    printf("s21_grep: %s: No such file or directory\n", optarg);
  }
  fclose(pt);
}

int grep(Flags flag, FILE* fp, int eflags, char* line_, char** argv, int y,
         int count, int file_amount, char** f_ptrns, int* f_count, int argc) {
  // printf("hello?\n");
  int x = 0;
  int c_count = 0;
  int string_counter=0;

  while (fgets(line_, 1024, fp)) {
    string_counter ++;
    x = regex(flag.pattern, line_, flag);
    if (flag.v ? x : !x) {
      
        c_count++;

        // printf("%d\n", c_count); it enters here only when regex is triggered

        if (flag.l == 1) {
          printf("%s\n", argv[optind]);
          break;
        }
        if (flag.o == 1) {
          flag_o(line_, argv[y], flag);
          continue;
        }
        if (flag.c != 1) {
          if (flag.n == 1) printf("%d:", string_counter);
          multifileprint(&flag, argv[optind]);
          printf("%s", line_);
          if (line_[strlen(line_) - 1] != '\n')
            printf("\n");  //если строка из конца файла добавляем \n
        }
      
    }
  }
  if (flag.c == 1) printf("%d\n", c_count);
  fclose(fp);
}

// printf("here?\n");
// if(fp==NULL)printf("NULL fp in grep func\n");
// printf("line 42\n");
// fseek(fp, 0, SEEK_SET);  // Move the cursor to the beginning of the file

// fgets(line_, 1024, fp);

// fseek(fp, 0, SEEK_SET);
// printf("line 37 grep\n");
// printf("e_ptrns[0]=%s", e_ptrns[0]);
/* noflags_ve_v(flag, fp, &count,  eflags, x, line_, argv, y, file_amount,
 * f_ptrns, f_count, argc); */
// exec e patterns

/*    if(flag.c==1&&flag.e!=1){
     while (fgets(line_, 1024, fp)) {
       x = regex(argv[y], line_, flag);
       if (!x) count++;
     }
     printf("%d\n", count);

   }
   //         printf("INSIDE THE e_ptrns:\n");
   // for(int n=0;n<2;n++){
   //     printf("%s\n", e_ptrns[n]);}
} */

void noflags_ve_v(Flags flag, FILE* fp, int* count, int eflags, int x,
                  char* line_, char** argv, int y, int file_amount,
                  char** f_ptrns, int* f_count, int argc) {
  if (flag.v == 1 && (flag.e == 1 || flag.f == 1)) {
    while (fgets(line_, 1024, fp)) {  // print e patterns
      int loop_count = (*count);
      while (loop_count > 0) {
        x = regex(flag.pattern, line_, flag);
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

      x = regex(argv[y], line_, flag);

      // printf("X in E loop=%d\n", x);
      if (x) {
        printf("%s", line_);
      }
    }
    // printf("\n");
  }
  /*     if(flag.f==1){
        flag_f(flag, fp, f_count, &f_ptrns, eflags, line_, argv, file_amount);
      } */
  if (flag.e == 1 || flag.f == 1) {
    flag_e(flag, fp, count, eflags, line_, argv, file_amount, argc);
  }
}
void multifileprint(Flags* flag, char* filename) {
  if (flag->file_counter > 1 && flag->h == 0) printf("%s:", filename);
}

void flag_e(Flags flag, FILE* fp, int* count, int eflags, char* line_,
            char** argv, int file_amount, int argc) {
  // fseek(fp, 0, SEEK_SET);
  int x;
  while (fgets(line_, 1024, fp)) {  // print e patterns
    int loop_count = (*count);
    // while (loop_count > 0) {
    // printf("e_ptrns[loop_count-1]=%s\n", e_ptrns[loop_count-1]);
    x = regex(flag.pattern, line_, flag);
    loop_count--;
    // printf("X in E loop=%d\n", x);
    if (!x) {
      multifileprint(&flag, argv[optind]);
      printf("%s", line_);
    }
  }
  fclose(fp);
}

/* void flag_f(Flags flag, FILE* fp, int* f_count, char*** f_ptrns, int eflags,
char* line_,char**  argv, int file_amount, int argc){ printf("f_ptrns[0]=%s",
*f_ptrns[0]);//я могу все писсать просто в паттерн для е флага, и потом при
любом из них on я вывожу

  int x;
  while (fgets(line_, 1024, fp)) {  // print e patterns
         int loop_count = *f_count;
        while (loop_count > 0) {
          //printf("f_ptrns[0]=%s", *f_ptrns[loop_count-1]);
          x = regex(*f_ptrns[loop_count - 1], line_, eflags);
          loop_count--;
          // printf("X in E loop=%d\n", x);
          if (!x) {
            multifileprint(file_amount, argv, argc);
            printf("%s", line_);
          }
        }
      }
} */

void flag_o(char* line_, char pattern[], Flags flag) {
  regex_t regex;
  regmatch_t matches[1];

  int return_value =
      regcomp(&regex, pattern, REG_EXTENDED | (flag.i ? REG_ICASE : 0));
  if (return_value) {
    printf("Could not compile regular expression.\n");
  }
  while ((regexec(&regex, line_, 1, matches, 0) == 0)) {
    printf("%.*s\n", (int)(matches[0].rm_eo - matches[0].rm_so),
           line_ + matches[0].rm_so);
    line_ += matches[0].rm_eo;
  }  //первый аргумент это длина паттерна, а второй сдвигает указатель в строке
     //чтобы от стоял на первом чаре, и потом печатает как раз длину паттерна.
}
