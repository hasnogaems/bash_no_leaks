#include <stdio.h>
#include <stdlib.h>
#include "parse_flags.h"

int main(int argc, char *argv[]) {
    FILE *fp;
    int line_index = 0;
    int previous = 10;
    int current = 0;
    int count = 0;
    int line_count=1;
    int new_line=1;

    flags Flag = parse_flags(argc, argv);
    fp = fopen(argv[argc - 1], "r");

    int c;
    while (1) {
        c = fgetc(fp);
        current = c;
        if (feof(fp)) break;

        if (previous == 10 && current == 10) {
            count++;
        }

        

        if (Flag.s == 1 && previous == 10 && current == 10 && count > 1) { //flag s
            continue;
        }
        if (current != 10) {
            //if (extra_line == 1) {printf("\n");}
            count = 0;
        }

        if(!Flag.b){
        if (Flag.n == 1&&line_count==new_line){ //flag n
        printf("    %d ", line_count);
        new_line=line_count+1;} //make it print line number only once for each new line
        if (Flag.n == 1&&current==10)
        line_count++;}
        //if(Flag.b==1 &&line_count==new_line&&!(previous == 10 && current == 10)){
        //printf("    %d ", line_count);
        //new_line=line_count+1;}
        //if (current==10)
        //line_count++;  //как комментить сразу несколько строк


        
        printf("%c", c);
        previous = c;
        
    }

    fclose(fp);
    return 0;
}

