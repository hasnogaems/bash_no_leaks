#include "h.h"

int open_file_and_i_flag(FILE** fp,Flags* flag, int file_name, char** argv, int* eflags){
  
    printf("in open_file argv[optind]=%s\n", argv[optind]);
    (*fp)=fopen(argv[optind],"r");//opening file
        if (fp == NULL) 
        {
            printf("Error opening file.\n");
            return -1;//debug
        }
         //here we store line from our file we grabbed with fgets
        if(flag->i==1){ //no distinction between upper and lowercase characters
        (*eflags)=REG_ICASE;
       // printf("EFLAGS IN MAIN=%d\n", eflags);
        }   
}
/* grep_file(){

} */

int grep(Flags flag,FILE* fp, int eflags, char* line_, char** argv, int y, int count, char** e_ptrns){
  printf("hello?\n");
    int x=0; 
    
    if (flag.e != 1 && flag.v != 1 && flag.c !=1)
      while (fgets(line_, 1024, fp)) {
        
        x = regex(argv[y], line_, eflags);
        if (!x) printf("%s", line_);
      }
      printf("here?\n");
      if(fp==NULL)printf("NULL fp in grep func\n");
//printf("line 42\n");
    fseek(fp, 0, SEEK_SET);  // Move the cursor to the beginning of the file
    
    fgets(line_, 1024, fp);

    fseek(fp, 0, SEEK_SET);
    printf("line 37 grep\n");
    printf("e_ptrns[0]=%s", e_ptrns[0]);
noflags_ve_v(flag, fp, &count, e_ptrns, eflags, x, line_, argv, y);
    // exec e patterns

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
}

void noflags_ve_v(Flags flag, FILE* fp, int* count, char** e_ptrns, int eflags, int x, char* line_, char** argv, int y){
    if (flag.v == 1 && flag.e == 1) {
      while (fgets(line_, 1024, fp)) {  // print e patterns
        int loop_count = (*count);
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
         int loop_count = (*count);
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
}