#include <stdio.h>
#include <stdlib.h>
#include "parse_flags.h"
#define no_argument        0
#define required_argument  1
#define optional_argument  2


flags parse_flags(int argc, char **argv) {
    int c;
    int digit_optind = 0;
  

  flags Flags={0};


  

    while (1) {
        int this_option_optind; //for debugging
        if (optind) {
            this_option_optind = optind;
        } else {
            this_option_optind = 1;
        }
        int option_index = 0;
        

        c = getopt_long(argc, argv, "+benstET", long_options, &option_index);
        if (c == -1)
            break;

        switch (c) {
        case 'b':
        Flags.b=1;
       // printf("flags.b=%d\n", Flags.b);
        //printf("b");
            break;
        case 'e':
        Flags.e=1;
        //printf("flag.e=%d\n", Flags.e);
       // printf("e");
            break;
        case 'n':
        Flags.n=1;
       // printf("flag.n=%d\n", Flags.n);
        //printf("n");
            break;
        case 's':
        Flags.s=1;
       // printf("flag.s=%d\n", Flags.s);
        //    printf("s");
            break;
        case 't':
        Flags.t=1;
       // printf("flag.t=%d\n", Flags.t);
        //    printf("t");
            break;
        case 'E':
        Flags.e=1;
        //printf("flag.e=%d\n", Flags.e);
            break;        
        case 'T':
        Flags.t=1;
       // printf("flag.t=%d\n", Flags.t);
            break;


        case '?':
            break;

        default:
            printf("?? Getopt returned character code 0%o ??\n", c);
        }
    }

    /*if (optind < argc) {
        printf("Non-parameter elements in ARGV: "); // for debuggin
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }*/

    

    return Flags;
}


int main(int argc, char *argv[]) {
    FILE *fp;
    int line_index = 0;
    int previous = 10;
    int current = 0;
    int count = 0;
    int line_count=1;
    int new_line=1;
    int s;

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
if (Flag.n == 1&&current==10)
        line_count++;
        
        //if(Flag.b==0){
         //   }
        if (Flag.n == 1&&line_count==new_line){ //flag n
        printf("%6.d\t", line_count);
        new_line=line_count+1;} //make it print line number only once for each new line
        
        if(Flag.b==1 &&line_count==new_line&&c!=10){
        printf("%6.d\t", line_count);
        new_line=line_count+1;}//тут рассинхрон
        if (Flag.b==1&&current==10&&!(previous == 10 && current == 10)){
                    line_count++;} //printf("%6.d\t", line_count); }//как комментить сразу несколько строк
        if (Flag.e==1){
            if(c<32&&c!=10&&c!=9){c=c+64;
            printf("^%c", c);
            if (Flag.b == 1&&current==10)
        line_count++; //this bitch was never executed, it was always broken by continue.
            continue;}
            if(c==127){c=c-128;
            printf("^%c", c);}

            if(c==10)
            printf("$");
        }
        


        
        printf("%c", c);
        previous = c;
        
    }

    fclose(fp);
    return 0;
}

