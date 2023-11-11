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
            
//printf("argv[y]=%d", y);
        x=regex(argv[y], line_);
        if(!x)
        
       // printf("11\n\n\n\n11");
            
            printf("PATTERN MATCHED! %s\n", line_);
        }
        /* while(count!=0){
        printf("e+ptrns[%d]=%s\n", count-1, e_ptrns[count-1]);
        count--;} */
        printf("PRE E LOOP COUNT=%d\n", count);
        
        fseek(fp, 0, SEEK_SET);// Move the cursor to the beginning of the file
        fgets(line_, 1024, fp);
        printf("PRE E LOOP fgets:=%s", line_ );
        fseek(fp, 0, SEEK_SET);
        printf("e_ptrns[count-1]=%s\n", e_ptrns[count-1]);
        printf("e_ptrns[count-2]=%s\n", e_ptrns[count-2]);
        while(count!=0){// exec e patterns
            while(fgets(line_, 1024, fp)){
                x=regex(e_ptrns[count-1], line_);
                //printf("X in E loop=%d\n", x);
                if(!x)
                printf("E PATTERN MATCHED! %s\n", line_);
        
            }
            fseek(fp, 0, SEEK_SET);
            count--;}
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
//printf("WHY count=%d", count);
    

    //fclose(fp);
    free(pattern);
    free(line_);
    free(e_ptrns);
    //free(e_ptrns);
    printf("Flag.e=%d", flag.e);

}


}

