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
    FILE *fp;
    char *pattern=malloc(sizeof(char));
   
    int c;
    int x;
    int y=parse_pattern(argc, argv);
    int file_name=parse_file_name(y, argv, argc);
    printf("parse_pattern=%d\n", y);
    printf("file name=%s\n", argv[file_name]);
    fp=fopen(argv[file_name],"r");
    //
//getopt(argc, argv);
    /* while(1){
        c=fgetc(fp);
        if(feof(fp))break;
        

    } */
    char pattern2[]="ab ";
    char line[]="abcsfsfsfgsgab";

   
   x=regex(argv[y], line);
    if(!x)
    for(int i=0;line[i]!='\0';i++)
    printf("%c", line[i]);
    
    
Flags flag;
// if(argc>1)flag=parse_flags(argc, argv);
// while(1&&argc>1){
//     c=fgetc(fp);
//     if(feof(fp)) break;
    
// }



//fclose(fp);
free(pattern);}

}

