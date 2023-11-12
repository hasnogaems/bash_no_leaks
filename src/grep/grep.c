#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "h.h"
#define no_argument       0
#define required_argument 1
#define optional_argument 2
int main(int argc, char *argv[]){
    if(argc==1)printf("Usage: grep [OPTION]... PATTERNS [FILE]...\nTry 'grep --help' for more information.\n");
    else{
        int count=0;
        int* pcount=&count;
        FILE *fp;
        char *pattern=malloc(100*sizeof(char));
        char **e_ptrns=(char **)malloc(1025*sizeof(char*));
        int c;
        int x;
        Flags flag=parse_flags(argc, argv); //parse flags
        int y=parse_pattern(argc, argv, e_ptrns, &count);  //parse pattern
        int file_name=parse_file_name(y, argv, argc);//parse file name
        
        fp=fopen(argv[file_name],"r");//opening file
        if (fp == NULL) {
            printf("Error opening file.\n");
            return -1;//debug
        }
        char *line_=(char *)malloc(1024*sizeof(char)); //here we store line from our file we grabbed with fgets
                
        if(flag.e!=1)
        while( fgets(line_, 1024, fp)){ 
            

        x=regex(argv[y], line_);
        if(!x)
              
            printf("%s\n", line_);
        }
        
        
        fseek(fp, 0, SEEK_SET);// Move the cursor to the beginning of the file
        fgets(line_, 1024, fp);
        
        fseek(fp, 0, SEEK_SET);
        
        // exec e patterns
        int e_count=count;
            while(fgets(line_, 1024, fp)&&count!=0){
                x=regex(e_ptrns[e_count-1], line_);
                //printf("X in E loop=%d\n", x);
                if(!x)
                printf("%s", line_);
                
        
            }
            
            
    free(pattern);
    free(line_);
    free(e_ptrns);
    

}


}

