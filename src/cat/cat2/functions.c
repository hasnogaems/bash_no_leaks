#include <stdio.h>
#include <stdlib.h>
#include "parse_flags.h"
int extralines(FILE *fp){
  
int c;
int enter=0;
int empty=0;
int previous;
int number_of_enters = 0 ;

while(1){
c=fgetc(fp);
if(feof(fp))break;
printf("%c", c);

if(previous==10&&c==10)
empty++;

previous=c;



}

printf("number of empty lines=%d\n", empty);
return empty;

}
