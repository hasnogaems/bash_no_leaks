#include "h.h"

int open_file_and_i_flag(FILE** fp,Flags* flag, int file_name, char** argv, int* eflags){
    //printf("argv[optind+1]=%s\n", argv[optind+1]);
    (*fp)=fopen(argv[optind+1],"r");//opening file
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

int raw_pattern(Flags flag,FILE* fp, int eflags, char* line_, char** argv, int y){
    int x=0;
    if (flag.e != 1 && flag.v != 1 && flag.c !=1)
//printf("here?\n");
      while (fgets(line_, 1024, fp)) {
        
        x = regex(argv[y], line_, eflags);
        if (!x) printf("%s", line_);
      }
}