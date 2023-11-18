#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
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
        
if(argc>1){
        c = getopt_long(argc, argv, "+bensvtET", long_options, &option_index);
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
        Flags.E=1;
        //printf("flag.e=%d\n", Flags.e);
            break;        
        case 'T':
        Flags.T=1;
       // printf("flag.t=%d\n", Flags.t);
            break;
        case 'v':
        Flags.v=1;
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
    }*/}
    

    

    return Flags;
}
