#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{   FILE *fp;

    fp=fopen(argv[1], "r");
if(fp) {

int c = 'a';
while(1){
c=fgetc(fp);
if(feof(fp))
    break;
printf("%c", c);  
 
 } 
// char c;
//    do {
//       c = fgetc (fp);
//       printf("%c", c);
//     } while (c != 'd');
//     fclose (fp);
 
 return 0;
 }
}