#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "h.h"
#define no_argument       0
#define required_argument 1
#define optional_argument 2
int main(int argc, char *argv[]){
    for(int i =0; i < argc; i++)
    {
        printf("%s\n",argv[i]);
    }
    if(argc==1)printf("Usage: grep [OPTION]... PATTERNS [FILE]...\nTry 'grep --help' for more information.\n");
    else{
        int count=0;
        int* e_count=&count;
        FILE *fp;
        char *pattern=malloc(100*sizeof(char));
        char **e_ptrns=(char **)malloc(1025*sizeof(char*));
        int c;
        int x;
        Flags flag=parse_flags(argc, argv, e_ptrns, e_count); //parse flags
        int y=parse_pattern(argc, argv, e_ptrns, &count);  //parse pattern
        //int file_name=parse_file_name(y, argv, argc);//parse file name
        int file_name=optind;
        printf("file name is %s its index is%d\n", argv[file_name], optind);
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
        
            
            while(fgets(line_, 1024, fp)){ //print e patterns
                int loop_count=count;
                while(loop_count>0){
                x=regex(e_ptrns[loop_count-1], line_);
                loop_count--;
                //printf("X in E loop=%d\n", x);
                if(!x){
                
                printf("MATCHED: %s", line_);}
                }

                
        
            }
    //         printf("INSIDE THE e_ptrns:\n");     
    // for(int n=0;n<2;n++){        
    //     printf("%s\n", e_ptrns[n]);}
       
    free(pattern);
    free(line_);
    free(e_ptrns);
    

}


}

