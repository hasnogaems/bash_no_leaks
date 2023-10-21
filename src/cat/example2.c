#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#define no_argument        0
#define required_argument  1
#define optional_argument  2

int main(int argc, char **argv) {
    int c;
    int digit_optind = 0;
  typedef struct flags{
    int b;
    int e;
    int n;
    int s;
    int t;

  }flags;

  flags Flags={0};

  

    while (1) {
        int this_option_optind;
        if (optind) {
            this_option_optind = optind;
        } else {
            this_option_optind = 1;
        }
        int option_index = 0;
        static struct option long_options[] = {
            {"number-nonblank", no_argument, 0, 'b'},
            {"number", no_argument, 0, 'n'},
            {"squeeze-blank", no_argument, 0, 's'},
            {0, 0, 0, 0}
        };

        c = getopt_long(argc, argv, "+benst", long_options, &option_index);
        if (c == -1)
            break;

        switch (c) {
        case 'b':
        Flags.b=1;
        printf("flags.b=%d\n", Flags.b);
        printf("b");
            break;
        case 'e':
        printf("flag.e=%d\n", Flags.e);
        printf("e");
            break;
        case 'n':
        printf("flag.n=%d\n", Flags.n);
        printf("n");
            break;
        case 's':
        printf("flag.s=%d\n", Flags.s);
            printf("s");
            break;
        case 't':
        printf("flag.t=%d\n", Flags.t);
            printf("t");
            break;

        case '?':
            break;

        default:
            printf("?? Getopt returned character code 0%o ??\n", c);
        }
    }

    if (optind < argc) {
        printf("Non-parameter elements in ARGV: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }

    exit(0);
}
