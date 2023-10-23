#include <stdio.h>
#include <stdlib.h>
#include "parse_flags.h"

int main(int argc, char *argv[])
{   FILE *fp;
int line_index=0;
//printf("argc=%d", argc);
int previous=0;
int current=0;

    flags Flag=parse_flags(argc, argv);
    fp=fopen(argv[1], "r");
    //int p=extralines(fp);


int c;
while(1){
c=fgetc(fp);
current=c;
if(feof(fp))break;
if(Flag.s==1&&previous==10&&current==10)
continue;
printf("%c", c);  
previous=c;
 
 } 
 fclose(fp); 
 return 0;
}


