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
        int count=100;
        int* pcount=&count;
        FILE *fp;
        char *pattern=malloc(100*sizeof(char));
        char **e_ptrns=(char **)malloc(1025*sizeof(char*));
        int c;
        int x;
        Flags flag=parse_flags(argc, argv); //parse flags
        int y=parse_pattern(argc, argv, e_ptrns, &count);
        printf("COUNT IN MAIN=%d", count); //parse pattern
        int file_name=parse_file_name(y, argv, argc);//parse file name
        printf("parse_pattern=%d\n", y);//debug
        printf("file name=%s\n", argv[file_name]);
        fp=fopen(argv[file_name],"r");//opening file
        if (fp == NULL) {
            printf("Error opening file.\n");
            return -1;//debug
        }
        char *line_=(char *)malloc(1024*sizeof(char)); //here we store line from our file we grabbed with fgets
        //

        //while(1){
        /* for(int i=0;i<5;i++){ fgets(line_, 1024, fp);
            printf("%s", line_);
        } */
        while( fgets(line_, 1024, fp)){
            

        x=regex(argv[y], line_);
        if(!x)
        
        printf("%s", line_);
            
            //printf("%s", line_);
        }
        //if(e_counter>1){
            //need counter of amounts of flag e, and then we read from array of e patterns
        // }

        //} 
        /* char pattern2[]="ab ";
        char line[]="abcsfsfsfgsgab"; */

    
    /* x=regex(argv[y], line);
        if(!x)
        for(int i=0;line[i]!='\0';i++)
        printf("%c", line[i]); */
        
        

    // if(argc>1)flag=parse_flags(argc, argv);
    // while(1&&argc>1){
    //     c=fgetc(fp);
    //     if(feof(fp)) break;
        
    // }



    //fclose(fp);
    free(pattern);
    free(line_);
    free(e_ptrns);
    //free(e_ptrns);
    printf("Flag.e=%d", flag.e);

}


}

