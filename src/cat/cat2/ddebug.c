#include <stdio.h>
#include <stdlib.h>

#include <getopt.h>
#define no_argument        0
#define required_argument  1
#define optional_argument  2
typedef struct flags{
    int b;
    int e;
    int n;
    int s;
    int t;

  }flags;

  static struct option long_options[] = {
            {"number-nonblank", no_argument, 0, 'b'},
            {"number", no_argument, 0, 'n'},
            {"squeeze-blank", no_argument, 0, 's'},
            {0, 0, 0, 0}
        };


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
        printf("flags.b=%d\n", Flags.b);
        printf("b");
            break;
        case 'e':
        Flags.e=1;
        printf("flag.e=%d\n", Flags.e);
        printf("e");
            break;
        case 'n':
        Flags.n=1;
        printf("flag.n=%d\n", Flags.n);
        printf("n");
            break;
        case 's':
        Flags.s=1;
        printf("flag.s=%d\n", Flags.s);
            printf("s");
            break;
        case 't':
        Flags.t=1;
        printf("flag.t=%d\n", Flags.t);
            printf("t");
            break;
        case 'E':
        Flags.e=1;
        printf("flag.e=%d\n", Flags.e);
            break;        
        case 'T':
        Flags.t=1;
        printf("flag.t=%d\n", Flags.t);
            break;


        case '?':
            break;

        default:
            printf("?? Getopt returned character code 0%o ??\n", c);
        }
    }

    if (optind < argc) {
        printf("Non-parameter elements in ARGV: "); // for debuggin
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }

    

    return Flags;
}


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
            count==0;
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