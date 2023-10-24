#include <stdio.h>
#include <stdlib.h>
#include "parse_flags.h"


int main(int argc, char *argv[]) {
    FILE *fp;
    int line_index = 0;
    int previous = 0;
    int current = 0;
    int extra_line = 0;
int count=1;
    flags Flag = parse_flags(argc, argv);
    fp = fopen(argv[argc - 1], "r");
int x;
    int c;
    while (1) {
        c = fgetc(fp);
        current = c;
        if (feof(fp)) break;
//x=(previous == 10 && current == 10);
//printf("X=%d!", x);
        if (previous == 10 && current == 10) {
            count++;
            if(count>2){
            count--;
             continue;}
        }



        /*{
            extra_line = 1;
        }*/

        

        //if (Flag.s == 1 && previous == 10 && current == 10 && extra_line == 1) {
            
            
       // }
        //if (current != 10) {
            //if (extra_line == 1) {printf("\n");}
           // extra_line = 0;
       // }

        printf("%c", c);
        previous = c;
    }

    fclose(fp);
    return 0;
}

