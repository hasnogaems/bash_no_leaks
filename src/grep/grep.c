#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "h.h"
#define no_argument       0
#define required_argument 1
#define optional_argument 2
int main(int argc, char *argv[]){
    FILE *fp;
    char *pattern=malloc(sizeof(char));
    fp=fopen(argv[argc-1],"r");
    int c;
    while(1){
        c=fgetc(fp);
        if(feof(fp))break;

    }
    char pattern2[]="[a-z]";
    char line[]="abcsfsfsfgsgab";
    
Flags flag;
// if(argc>1)flag=parse_flags(argc, argv);
// while(1&&argc>1){
//     c=fgetc(fp);
//     if(feof(fp)) break;
    
// }




free(pattern);

}

