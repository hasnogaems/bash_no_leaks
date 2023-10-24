#include <stdio.h>
#include <stdlib.h>
#include "parse_flags.h"

int main(int argc, char *argv[]) {
    FILE *fp;
    int line_index = 0;
    int previous = 10;
    int current = 0;
    int count = 0;

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

        

        if (Flag.s == 1 && previous == 10 && current == 10 && count > 1) {
            continue;
        }
        if (current != 10) {
            //if (extra_line == 1) {printf("\n");}
            count = 0;
        }

        printf("%c", c);
        previous = c;
    }

    fclose(fp);
    return 0;
}

