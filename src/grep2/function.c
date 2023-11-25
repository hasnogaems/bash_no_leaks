#include "h.h"

void open_file_and_i_flag(FILE* fp,Flags* flag, int file_name, char** argv, int* eflags){
    fp=fopen(argv[file_name],"r");//opening file
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